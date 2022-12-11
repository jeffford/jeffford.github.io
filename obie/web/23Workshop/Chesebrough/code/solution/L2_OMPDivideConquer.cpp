#include <iostream>
#include <omp.h>

#define NUM 16
#define NT 4
#define SEQUENTIAL_CUTOFF 4
#define PRINT 5

using namespace std;

class VecAdd {
   int *arr1, *arr2, *res, len; //fields to know what to do
public:
   VecAdd(int _arr1[], int _arr2[], int _res[], int _num) {
      arr1 = _arr1;
	  arr2 = _arr2;
	  res  = _res;
	  len = _num;
   }


   // vector add serial divide and conquer version
   int addDC(int lo, int hi) 
   {
      if (hi-lo < SEQUENTIAL_CUTOFF) {
         for(int i=lo; i < hi; ++i) {
            res[i] = arr1[i] + arr2[i];
         }
      } else {
         VecAdd *left  = new VecAdd(arr1, arr2, res, NUM);
	 VecAdd *right = new VecAdd(arr1, arr2, res, NUM);
         left->addDC(lo,(hi+lo)/2);
		 right->addDC((hi+lo)/2,hi);
	  }
   return 0;
   }

   
   // vector add parallel divide and conquer version
   int addDCOMP(int lo, int hi) 
   {
      if (hi-lo < SEQUENTIAL_CUTOFF) {
         for(int i=lo; i < hi; ++i) {
            res[i] = arr1[i] + arr2[i];
         }
      } else {
         VecAdd *left  = new VecAdd(arr1, arr2, res, NUM);
	 VecAdd *right = new VecAdd(arr1, arr2, res, NUM);
#pragma omp task shared(left) firstprivate(lo,hi)
           left->addDC(lo,(hi+lo)/2) ;
	 right->addDC((hi+lo)/2,hi);
#pragma omp taskwait
      }
   return 0;
   }
};


int main()
{
	int * arr1, * arr2, * res;
	arr1 = new int[NUM]; //array ints
	arr2 = new int[NUM]; //array ints
	res  = new int[NUM]; //array ints

	// initialize array input
	cout << "\npreparing array arr1\n";
	for (int i=0; i < NUM; ++i) {
		arr1[i] = i;
		if (i < PRINT) cout << arr1[i] << endl;
	}

	cout << "\npreparing array arr2\n";
	for (int i=0; i < NUM; ++i) {
		arr2[i] = 28 - 3*i;
		if (i < PRINT) cout << arr2[i] << endl;
	}

        VecAdd *myVecAdd = new VecAdd( arr1, arr2, res, NUM);
	cout << "\ncomputing array Divide and Conquer serial\n";
	myVecAdd->addDC(0, NUM);
	for (int i=0; i < NUM; ++i) {
		if (i < PRINT) cout << res[i] << endl;
	}
	
	cout << "\ncomputing array Divide and Conquer parallel\n";
        //cout << "Number of workers = " << __cilkrts_get_nworkers()  << endl;
#pragma omp parallel
{
        #pragma omp single
        cout << "Number of workers = " << omp_get_num_threads()  << endl;
	myVecAdd->addDCOMP(0, NUM);
}
	for (int i=0; i < NUM; ++i) {
		if (i < PRINT) cout << res[i] << endl;
	}
}
