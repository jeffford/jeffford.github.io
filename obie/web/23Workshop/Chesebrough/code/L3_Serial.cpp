#include <iostream>
#include <omp.h>
#define NUM 16
using namespace std;

int prefix_sum(int  input[], int  output[], int N)
{
	output[0] = input[0];
	for(int i=1; i < N; i++)
		output[i] = output[i-1]+input[i];
	return 1;
}

int main()
{

	int * output, * input;
	output = new int[NUM]; //array ints
	input  = new int[NUM]; //array ints

	// initialize array input
	cout << "preparing input array \n";
	for (int i=0; i < NUM; ++i) {
		input[i] = i+1;
		if (i < 10) cout << input[i] << endl;
	}

	cout << "\ncomputing output array sequential\n";
	prefix_sum(input, output, NUM);

	for (int i=0; i < NUM; ++i) {
		if (i < 10) cout << output[i] << endl;		
	}

	return 0;
}

