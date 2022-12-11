#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include "cilktime.h"

#define MAX_SIZE 1000



void generate_list(int * x, int n) {
   int i,j,t;
   for (i = 0; i < n; i++)
     x[i] = i;
   for (i = 0; i < n; i++) {
     j = rand() % n;
     t = x[i];
     x[i] = x[j];
     x[j] = t;
   }
}

void print_list(int * x, int n) {
   int i;
   for (i = 0; i < n; i++) {
      printf("%d ",x[i]);
   } 
}

void merge(int * X, int n, int * tmp) {
   int i = 0;
   int j = n/2;
   int ti = 0;

   while (i<n/2 && j<n) {
      if (X[i] < X[j]) {
         tmp[ti] = X[i];
         ti++; i++;
      } else {
         tmp[ti] = X[j];
         ti++; j++;
      }
   }
   while (i<n/2) { /* finish up lower half */
      tmp[ti] = X[i];
      ti++; i++;
   }
      while (j<n) { /* finish up upper half */
         tmp[ti] = X[j];
         ti++; j++;
   }
   memcpy(X, tmp, n*sizeof(int));

} // end of merge()

void mergesort(int * X, int n, int * tmp)
{
   if (n < 2) return;

   mergesort(X, n/2, tmp);
   mergesort(X+(n/2), n-(n/2), tmp);

    /* merge sorted halves into sorted list */
   merge(X, n, tmp);
}


int main()
{
   int n = 100;
   int data[MAX_SIZE], tmp[MAX_SIZE];
  
   generate_list(data, n);
   printf("List Before Sorting...\n");
   print_list(data, n);
   unsigned long long start = cilk_getticks();   
   mergesort(data, n, tmp);
   unsigned long long stop  = cilk_getticks();
   unsigned long long ticks = stop - start;
   printf("\nList After Sorting...\n");
   print_list(data, n);
   printf("\nTime: %g\n",cilk_ticks_to_seconds(ticks)*1000);
}

