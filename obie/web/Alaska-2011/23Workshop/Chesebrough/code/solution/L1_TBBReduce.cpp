#include <iostream>
#include <tbb/task_scheduler_init.h>
#include <tbb/parallel_reduce.h>
#include <tbb/blocked_range.h>
#include <tbb/tick_count.h>

#define NUM 16

using namespace std;
using namespace tbb;

class Sum {
   int *arr;       // fields to know what to do
   long ans;       // for communicating result
public:
   Sum(int a[], int num) {
      arr=a, ans = 0;
      for (int i=0; i < num; ++i)
      {
         arr[i] = i+1;  //intialize array
      }
   }

   int sum(int lo, int hi) 
   {
      long ans = 0;
      for(int i=lo; i < hi; ++i) {
         ans += arr[i];
      }
      return ans;
   }

};

class SumParReduce {
   int *arr;
public:
   int ans;
   void operator()( const blocked_range<size_t>& r)
   {
      for (size_t i=r.begin(); i!= r.end(); ++i) {
        ans += arr[i];
      }      
   }

   SumParReduce( SumParReduce& x, split ) : arr(x.arr), ans(0) 
   {
      ans = 0;
   }

   SumParReduce(int a[]) : arr(a), ans(0) {}

   void join (const SumParReduce& y) {ans += y.ans;}

};


int main()
{

    int * arr;
    long ans=0, total=0;
    arr = new int[NUM];
    double start, stop;

    task_scheduler_init init;

    // first lesson - serial computation of sum of array
    Sum *mySum = new Sum(arr,NUM);
    cout << endl <<  "Computing serial sum of array " << mySum->sum(0,NUM) << endl;


    // Fourth Lesson - using the OpenMP worksharing construct 
    // "omp for" to automatically
    // divide the loop into a number of chucks of iterations
    // equal to the number of processors
    cout << endl << "Second parallel approach TBB Reduce" << endl;
    SumParReduce myParSum(arr);
    parallel_reduce (blocked_range<size_t>(0,NUM), myParSum, auto_partitioner());
    total = myParSum.ans;
    cout << "Total: " << total << endl;

    return 0;
}

