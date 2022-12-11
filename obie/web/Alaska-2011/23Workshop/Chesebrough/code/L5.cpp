#include <iostream>
#include <omp.h>
#ifdef WINDOWS
#include <windows.h> 
#endif

#define SIZE 100

using namespace std;
omp_nest_lock_t _lock;

// C++ version of a simple stack using omp_nest_locks
// This example is NOT intended to show how to create a concurrent stack
// it shows the issues that arise with critical sections and how to implement sameidea using nest_locks
// when a thread locks itself out by nested calls
// such as peek () having critical section then calling pop() that has same critical section
// a work around is to assign ownership at the highest level function - peek
// and test ownership before reacquring same lock by same thread

template <class T>
class StackNestedLocks {
public:

   StackNestedLocks()	
   {
      omp_init_nest_lock (&_lock);
      index = -1;
   };

   bool isEmpty()
   {  
      bool test;
      omp_set_nest_lock (&_lock);
      test = ( index==-1);
      omp_unset_nest_lock (&_lock);
      return test;
   };

   void push(T i)
   {
      omp_set_nest_lock (&_lock);
      array[++index] = i;
      omp_unset_nest_lock (&_lock);
   };

   T pop()
   {
      int tmp;
      omp_set_nest_lock (&_lock);
      tmp = array[index--];
      omp_unset_nest_lock (&_lock);
      return tmp;
   };

   T peek()
   { 
      //return array[index];
      int tmp;
#pragma omp critical (stack)
      {
         tmp = pop();
	 push(tmp);
      }
      return tmp;
   };

   ~StackNestedLocks()
   {
      omp_destroy_nest_lock (&_lock);
   };

private:
   int index;
   bool owner;
   T array[SIZE]; 
};
 


// C++ version of a simple stack using critical sections
// This example is NOT intended to show how to create a concurrent stack
// it shows the issues that arise with critical sections
// when a thread locks itself out by nested calls
// such as peek () having critical section then calling pop() that has same critical section
// a work around is to assign ownership at the highest level function - peek
// and test ownership before reacquring same lock by same thread

template <class T>
class StackCriticalSections {
public:
   StackCriticalSections()	
   {
      owner = false;
      index = -1;
   };

   bool isEmpty()
   { 
      return index==-1;
   };

   void push(T i)
   {
      if (owner == true) {
         array[++index] = i;
      } else {
      #pragma omp critical (stack)
         {
	    array[++index] = i;
	 }
      }
   };

   T pop()
   {
      int tmp;
      if (owner == true) {
         tmp = array[index--];
      } else {
     #pragma omp critical (stack)
         {
            tmp = array[index--];
         }
      }

      return tmp;
   };

   T peek()
   { 
      //return array[index];
	  int tmp;
#pragma omp critical (stack)
      {
         owner = true;
         tmp = pop();
	 push(tmp);
	 owner = false;
      }
      return tmp;
   };
private:
   int index;
   bool owner;
   T array[SIZE]; 
};



int main()
{
   StackNestedLocks<int> myIntStackNestedLocks;
   cout << "Initializing Stack for serial access" << endl;
   myIntStackNestedLocks.push(31);
   myIntStackNestedLocks.push(29);
   myIntStackNestedLocks.push(27);
   myIntStackNestedLocks.peek();
   myIntStackNestedLocks.pop();
   cout << myIntStackNestedLocks.peek() << endl;

   cout << endl << "Initializing Stack for parallel access using omp_nest_locks" << endl;
   cout << "Note: stack order may (likely will) be different from serial order" << endl;
   cout << "Note: what we are testing is whether or not we deadlock" << endl;

#pragma omp parallel sections
   {
#pragma omp section
   myIntStackNestedLocks.push(31);
#pragma omp section
   myIntStackNestedLocks.push(29);
#pragma omp section
   myIntStackNestedLocks.push(27);
#pragma omp section
   myIntStackNestedLocks.peek();
#pragma omp section
   myIntStackNestedLocks.pop();
   }
   cout << myIntStackNestedLocks.peek() << endl;





   StackCriticalSections<int> myIntStackCriticalSections;
   cout << "\n\nInitializing Stack for serial access" << endl;
   myIntStackCriticalSections.push(31);
   myIntStackCriticalSections.push(29);
   myIntStackCriticalSections.push(27);
   myIntStackCriticalSections.peek();
   myIntStackCriticalSections.pop();
   cout << myIntStackCriticalSections.peek() << endl;

   cout << endl << "Initializing Stack for parallel access using omp critical sections" << endl;
   cout << "Note: stack order may (likely will) be different from serial order" << endl;
   cout << "Note: what we are testing is whether or not we deadlock" << endl;

#pragma omp parallel sections
   {
#pragma omp section
   myIntStackCriticalSections.push(31);
#pragma omp section
   myIntStackCriticalSections.push(29);
#pragma omp section
   myIntStackCriticalSections.push(27);
#pragma omp section
   myIntStackCriticalSections.peek();
#pragma omp section
   myIntStackCriticalSections.pop();
   }
   cout << myIntStackCriticalSections.peek() << endl;


return 0;
}

