#include <iostream>

#define NUM 16

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

int main(void)
{
    int * arr;
    arr = new int[NUM];
    double start, stop;

    // first lesson - serial computation of sum of array
    Sum *mySum = new Sum(arr,NUM);
    cout << endl <<  "Computing serial sum of array " << mySum->sum(0,NUM) << endl;
    return 0;
}
