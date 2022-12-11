#include <iostream>
#include <omp.h>

#define NUM 16
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

   // vector add serial version
   int add(int lo, int hi) 
   {
       for(int i=lo; i < hi; ++i) {
          res[i] = arr1[i] + arr2[i];
       }
       return 0;
   }
   
   // vector add serial version
   int addparallel(int lo, int hi) 
   {
#pragma omp parallel for
      for(int i=lo; i < hi; ++i) {
         res[i] = arr1[i] + arr2[i];
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

	cout << "\ncomputing array sequential\n";
	VecAdd *myVectAdd = new VecAdd(arr1, arr2, res, NUM);
	myVectAdd->add(0, NUM);
	for (int i=0; i < NUM; ++i) {
		if (i < PRINT) cout << res[i] << endl;
	}

	cout << "\ncomputing array OMP parallel for\n";
	VecAdd *myVectAddOMP = new VecAdd(arr1, arr2, res, NUM);
	myVectAddOMP->addparallel(0, NUM);
	for (int i=0; i < NUM; ++i) {
		if (i < PRINT) cout << res[i] << endl;
	}
}
