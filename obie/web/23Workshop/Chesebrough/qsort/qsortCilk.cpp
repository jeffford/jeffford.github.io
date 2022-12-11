#include <stdio.h>
#include "quicksort.h"
#include "tbb/concurrent_queue.h"
#include <cilk/cilk.h>
#define BOOL bool
#define TRUE true
#define FALSE false

// Number of integers to sort
#define NN 100

// Size of partition to trigger InsertionSort execution rather than more QuickSort
#define THRESHOLD 5

long tCount = 0; 
BOOL Done = FALSE;
int *A;

tbb::concurrent_queue<qSortIndex> Q;

void init_data()
{
	int i,j,t;
	for (i = 0; i < NN; i++)
		A[i] = i;
	for (i = 0; i < NN; i++) {
		j = rand() % NN;
		t = A[i]; 
		A[i] = A[j];
		A[j] = t;
	}
}

int Partition (int p, int r)
{	int x = A[p];
	int k = p;
	int l = r+1;
	int t;

	do k++; while ((A[k] <= x) && (k < r));
	do l--; while (A[l] > x);

	while (k < l) {
		t = A[k];  A[k] = A[l];  A[l] = t;
		do k++; while (A[k] <= x);
		do l--; while (A[l] > x);
	}
	t = A[p];  A[p] = A[l];  A[l] = t;
	return l;
}

void InsertionSort(int p, int r)
{
  int i, j, v;
  for (i = p+1; i <= r; ++i) {
    v = A[i]; 
    j = i;
    while (A[j-1] > v) {
		A[j] = A[j-1]; j--;
      if (j <= p) break;
    }
    A[j] = v;
  }
}

void QuickSort(int N)
{
	int p, r, q;
	qSortIndex d, d1, d2;
	int t = 0;

	while (1) {
		while (!Q.try_pop(d)) {
			//pause? or else spin-wait with no wait
			if (Done) break;  // if Done, no more need to process anything
		}
		if (Done) break; // signal to terminate threads 
		p = d.lo;
		r = d.hi;

		if (p == r) {
		//#pragma omp atomic
			++tCount;
			if (tCount == N) Done = TRUE;   // Signal main thread that sorting is done
		}
		else if (r-p <= THRESHOLD) {
			InsertionSort(p, r);
		//#pragma omp atomic
			tCount += (r-p)+1;
			if (tCount == N) Done = TRUE;   // Signal main thread that sorting is done
		}
		else if (p < r) {
			q = Partition(p, r);
		//#pragma omp atomic
			++tCount;
			d1.lo = p;
			d1.hi = q-1;
			cilk_spawn (Q.push(d1));
			d2.lo = q+1;
			d2.hi = r;
			cilk_spawn(Q.push(d2));
                        cilk_sync;
		}
	}
}

int main(int argc, char* argv[])
{
  int i;
  qSortIndex e1;
  int NumToSort = NN;

  A = new int[NN];

  init_data();

  for (i = 0; i < NN; i++) printf("%3d ",A[i]);
  printf("\n\n");

  tCount = 0L;

  e1.lo = 0; e1.hi = NumToSort-1;
  Q.push(e1);

  QuickSort(NN);


  for ( i = 0; i < NN; i++) printf("%3d ",A[i]);
  printf("\nTCOUNT = %ld\n", tCount);
  delete A;
  return 0;
}
