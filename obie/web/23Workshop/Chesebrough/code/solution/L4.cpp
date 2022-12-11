#include <iostream>

#ifdef WINDOWS
#include <windows.h> 
#endif
#include "OMP_NestedScopeLock.h"

// this Bank Account Example is an example of using Scoped Locking in OpenMP
// This is a class for guard objects using OpenMP
//  It is adapted from the book
//  "Pattern-Oriented Software Architecture". 
//  See article here: http://www.thinkingparallel.com/2006/08/21/scoped-locking-vs-critical-in-openmp-a-personal-shootout/

using namespace std;

// C++ version of an interlocked bank account using scoped locking
class BankAccountScoped {
private:
   double _balance;
   omp_nest_lock_t BASLock; //define nest lock variable BASLock
public:
   BankAccountScoped()  //Bank Account Constructor
   {
      _balance = 500.0;
      omp_init_nest_lock (&BASLock);  // Init a lock on BASLock
   }

   void deposit(double amount) {
      OMP_NestedScopeLock myBASLock (BASLock);  //Construct Class OMP_Ne.. initially with BASLock passed to constructor
      _balance += amount;
   }   //note: deposit method goes out of scope, so OMP_Nested... destructor called, which unlocks the lock
   void withdraw(double amount) {
      OMP_NestedScopeLock myBASLock (BASLock);
      if(_balance >= amount) 
      {
         double temp;
	 temp = getBalance();
	 setBalance(temp - amount);
      }
   }
   double getBalance() {
      OMP_NestedScopeLock myBASLock (BASLock);
      return _balance;
   }
   
   void setBalance(int x) {
      OMP_NestedScopeLock myBASLock (BASLock);
      _balance = x;
   }
      
   ~BankAccountScoped()
   {
      omp_destroy_nest_lock (&BASLock);
   }

};

// C++ version of an interlocked bank account using OpenMP Critical Section
class BankAccountCritical {
private:
   double _balance;
public:
   BankAccountCritical()
   {
      _balance = 500.0;
   }

   void deposit(double amount) {
#pragma omp critical 
      {
         _balance += amount;
      }
   }

   void withdraw(double amount) {
#pragma omp critical 
      {
         if(_balance >= amount) _balance -= amount;
      }
   }

   double getBalance() {
      double temp;
#pragma omp critical 
      {
         temp =  _balance;
      }
      return temp;
   }
   
   void setBalance(int x) {
#pragma omp critical 
      {
         _balance = x;
      }
   }
      
};


int main()
{
   BankAccountScoped *my_accountS = new BankAccountScoped;
   cout << "Testing Scope Locked Bank Account" << endl;
#pragma omp parallel sections
   {
#pragma omp section
   my_accountS->deposit(100.00);
#pragma omp section
   my_accountS->deposit(150.00);
#pragma omp section
   my_accountS->deposit(200.00);
#pragma omp section
   my_accountS->deposit(250.00);
#pragma omp section
   my_accountS->withdraw(200.00);
   }
   cout.precision(2);
   cout << "After all is said and done, my balance should be $1000.00 \n";
   cout << fixed << "and was just computed to be " << my_accountS->getBalance() << endl;


   BankAccountCritical *my_accountC = new BankAccountCritical;
   cout << "\n\nTesting Critical Section protected Bank Account" << endl;
#pragma omp parallel sections
   {
#pragma omp section
   my_accountC->deposit(100.00);
#pragma omp section
   my_accountC->deposit(150.00);
#pragma omp section
   my_accountC->deposit(200.00);
#pragma omp section
   my_accountC->deposit(250.00);
#pragma omp section
   my_accountC->withdraw(200.00);
   }
   cout.precision(2);
   cout << "After all is said and done, my balance should be $1000.00 \n";
   cout << fixed << "and was just computed to be " << my_accountC->getBalance() << endl;
return 0;
}

