#include <iostream>
#include <omp.h>

#define NUM 16
#define NT 4
#define SEQUENTIAL_CUTOFF 4

using namespace std;

class Sum {
   int *arr; //fields to know what to do
   long ans;       // for communicating result
   int num;
public:
   Sum(int a[], int _num) {
      arr=a, ans = 0; num=_num;
   }

   int initialize() {
      ans = 0;
      for (int i=0; i < num; ++i)
      {
         arr[i] = i+1;  //intialize array
      }
  
      return 1;
   }

   int sum(int lo, int hi) 
   {
      long ans = 0;
      for(int i=lo; i < hi; ++i) {
         ans += arr[i];
      }
      return ans;
   }


   int sum(bool parallel, int lo, int hi) 
   {
      long ans = 0;
#pragma omp parallel
  #pragma omp single
      cout << "Number of threads = " << omp_get_num_threads() << endl;
#pragma omp parallel for reduction(+:ans)
      for(int i=lo; i < hi; ++i) {
         ans += arr[i];
      }  
      return ans;
   }


   int sumDC(int lo, int hi) 
   {
      long ans = 0;
      if (hi-lo < SEQUENTIAL_CUTOFF) {
         for(int i=lo; i < hi; ++i) {
            ans += arr[i];
         }
      } else {
         Sum *left  = new Sum(arr, NUM);
   	 Sum *right = new Sum(arr, NUM);
         int LeftAns = left->sumDC(lo,(hi+lo)/2);
	 int RightAns = right->sumDC((hi+lo)/2,hi);

	 ans = LeftAns + RightAns;
      }
      return ans;
   }
   

   int sumDC(bool parallel, int lo, int hi) 
   {
      long ans = 0;
      if (hi-lo < SEQUENTIAL_CUTOFF) {
         for(int i=lo; i < hi; ++i) {
            ans += arr[i];
         }
      } else {
	     Sum *left  = new Sum(arr, NUM);
	   	 Sum *right = new Sum( arr, NUM);
		 int LeftAns;
		 int RightAns;
		 #pragma omp task shared(LeftAns) firstprivate(lo,hi)
                   LeftAns = left->sumDC(true, lo,(hi+lo)/2);
		 RightAns = right->sumDC(true, (hi+lo)/2,hi);
		 #pragma omp taskwait
		 ans = LeftAns + RightAns;
	  }
      return ans;
   }
};


int main()
{

    int * arr;
    long ans=0, res[NT], total=0;
    arr = new int[NUM];
    double start, stop;

    // first lesson - serial computation of sum of array
    Sum *mySum = new Sum(arr,NUM);
    mySum->initialize();
    cout << endl <<  "Computing serial sum of array " << mySum->sum(0,NUM) << endl;



    // second lesson - manual computation of partial sums
    // then computing final sum
    // this is still al serial computations
    cout << endl << "Computing partial sums with fixed partitioning..." << endl;
    res[0] = mySum->sum(0*NUM/4,1*NUM/4);
    res[1] = mySum->sum(1*NUM/4,2*NUM/4);
    res[2] = mySum->sum(2*NUM/4,3*NUM/4);
    res[3] = mySum->sum(3*NUM/4,4*NUM/4);
    cout << "Computing 1st partial sum of array " << res[0] << endl;
    cout << "Computing 2nd partial sum of array " << res[1] << endl;
    cout << "Computing 3rd partial sum of array " << res[2] << endl;
    cout << "Computing 4th partial sum of array " << res[3] << endl;
    cout << "Total: " << res[0] + res[1] + res[2] + res[3] << endl;



    // Third Lesson - First parallel approach (SPMD) using Thread ID
    // Each thread computes its own partial sum and the results for 
    // each thread are assigned to the array threadSum which is 
    // indexed by thread ID
    cout << endl << "First parallel approach (SPMD) using Thread ID" << endl;
    Sum *threadSum;
    threadSum = new Sum(arr, NUM);
    // now creating new instance of Sum Class
    // creating a parallel pool of threads (equal to the number of threads specified by NT)
#pragma omp parallel num_threads(NT)
    {
#pragma omp single
      {
         cout << "Number of threads = " << omp_get_num_threads() << endl;
      }
      int tid;
      tid = omp_get_thread_num();  //get each threads thread ID
      res[tid] = threadSum->sum(tid*NUM/NT,(tid+1)*NUM/NT);  // use thread ID to hold results
    }
    // add all the partial results to get a grand total
    for (int i=0; i< NT; ++i) {
      total += res[i];
      cout << "Partial sum for thread(" << i << ") = " << res[i] <<  endl;
    }
    cout << "Total: " << total << endl;




    // Fourth Lesson - using the OpenMP worksharing construct 
    // "omp for" to automatically
    // divide the loop into a number of chucks of iterations
    // equal to the number of processors
    cout << endl << "Second parallel approach OMP parallel for" << endl;
    Sum *myOMPfor =  new Sum(arr, NUM);
    total = myOMPfor->sum(true, 0, NUM);
    cout << "Total: " << total << endl;




    // Fifth Lesson - A serial Divide and conquer approach
    cout << endl << "Computing sum of with Divide & Conquer class (serial) " << endl;
    Sum *mySumDnC = new Sum(arr, NUM);
    cout << "sum = " << mySumDnC->sumDC(0,NUM) << endl;



    // Sixth Lesson - A serial Divide and conquer approach
    cout << endl << "Computing sum of with Divide & Conquer class (parallel) " << endl;
    Sum *mySumDnCparallel = new Sum(arr, NUM);
#pragma omp parallel 
    {
#pragma omp single
      {
         cout << "Number of threads = " << omp_get_num_threads() << endl;
         cout << "sum = " << mySumDnCparallel->sumDC(true, 0,NUM) << endl;
      }

    }

    return 0;
}

