#include <iostream>
#include <omp.h>

#define NUM 16
#define NT 4
#define SEQUENTIAL_CUTOFF 4

using namespace std;

class Sum {
   int *arr; //fields to know what to do
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


   int sum(bool parallel, int lo, int hi) 
   {
      long ans = 0;
#pragma omp parallel for reduction(+:ans)
      for(int i=lo; i < hi; ++i) {
         ans += arr[i];
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
    cout << endl <<  "Computing serial sum of array " << mySum->sum(0,NUM) << endl;


    // Fourth Lesson - using the OpenMP worksharing construct 
    // "omp for" to automatically
    // divide the loop into a number of chucks of iterations
    // equal to the number of processors
    cout << endl << "Second parallel approach OMP parallel for" << endl;
    Sum *myOMPfor =  new Sum(arr, NUM);
    total = myOMPfor->sum(true, 0, NUM);  //call parallel version of sum :true
    cout << "Total: " << total << endl;

#pragma omp parallel
  #pragma omp single
      cout << "Number of threads = " << omp_get_num_threads() << endl;
    return 0;
}

