#include <iostream>

#define NUM 16
#define NT 4

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


    return 0;
}

