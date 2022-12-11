#include <iostream>

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
      arr=a, ans = 0, num=_num;
   }

   int initialize()
   {
      for (int i=0; i < num; ++i)
      {
         arr[i] = i+1;  //intialize array
      }
      return 0;
   }

   int sum(int lo, int hi) 
   {
      long ans = 0;
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
         Sum *left  = new Sum(arr, (hi-lo)/2);
   	 Sum *right = new Sum(arr, (hi-lo)/2);
         int LeftAns = left->sumDC(lo,(hi+lo)/2);
	 int RightAns = right->sumDC((hi+lo)/2,hi);

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


    // Fifth Lesson - A serial Divide and conquer approach
    cout << endl << "Computing sum of with Divide & Conquer class (serial) " << endl;
    Sum *mySumDnC = new Sum(arr, NUM);
    mySumDnC->initialize();
    cout << "sum = " << mySumDnC->sumDC(0,NUM) << endl;


    return 0;
}
