#include <iostream>
#include <cilk/cilk.h>
#define NUM 63 
using namespace std;

int prefix_sum(int  input[], int  output[], int lo, int hi, int *sum, int fromleft)
{
        int mid, sumleft, sumright;
        *sum =0;

	if (hi - lo == 0) {  // threashold = 1
               *sum = input[lo];
               output[lo] = fromleft + *sum;          
        } else {
               mid = (lo + hi)/2;
               cilk_spawn (prefix_sum(input, output, lo, mid, &sumleft, fromleft));
               prefix_sum(input, output, mid+1, hi, &sumright, fromleft + sumleft);
               *sum = sumleft + sumright;
               cilk_sync;
	} 
       

        return 1;
}

int main()
{

	int * output, * input, sum, fromleft;
	output = new int[NUM]; //array ints
	input  = new int[NUM]; //array ints

	// initialize array input
	cout << "preparing input array \n";
	for (int i=0; i < NUM; ++i) {
		input[i] = i+1;
		if (i < 10) cout << input[i] << endl;
	}
        output[0] = input[0];

	cout << "\ncomputing output array parallel\n";
	prefix_sum(input, output, 0, NUM-1, &sum, 0);

	for (int i=0; i < NUM; ++i) {
		if (i < 10) cout << output[i] << endl;		
	}

	return 0;
}

