#include <iostream>

#ifdef WINDOWS
#include <windows.h> 
#endif

using namespace std;

// C++ version of an interlocked bank account using scoped locking
class BankAccountScoped {
private:
   double _balance;
public:
   BankAccountScoped()  //Bank Account Constructor
   {
      _balance = 500.0;
   }

   void deposit(double amount) {
      _balance += amount;
   }  
   void withdraw(double amount) {
      if(_balance >= amount) 
      {
         double temp;
	 temp = getBalance();
	 setBalance(temp - amount);
      }
   }
   double getBalance() {
      return _balance;
   }
   
   void setBalance(int x) {
      _balance = x;
   }
      
   ~BankAccountScoped()
   {
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
      {
         _balance += amount;
      }
   }

   void withdraw(double amount) {
      {
         if(_balance >= amount) _balance -= amount;
      }
   }

   double getBalance() {
      double temp;
      {
         temp =  _balance;
      }
      return temp;
   }
   
   void setBalance(int x) {
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

