#include <stdio.h>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <cstdlib>
#include <cctype>
#include "tbb/parallel_reduce.h"
#include "tbb/task_scheduler_init.h"
#include "tbb/blocked_range.h"
#include "tbb/tick_count.h"

using namespace std;
using namespace tbb;

long long num_steps =  1000000000;

class MyPi {
  double *const my_step;
public:
  double sum;
  void operator()( const blocked_range<size_t>& r ) 
  {
    double step = *my_step;
    double x;
    for (size_t i=r.begin(); i!=r.end(); ++i)
    {
      x = (i + .5)*step;
      sum = sum + 4.0/(1.+ x*x);
    }
  }

  MyPi( MyPi& x, split ) : my_step(x.my_step), sum(0) {}

  void join( const MyPi& y ) {sum += y.sum;}

  MyPi(double *const step) : my_step(step), sum(0) {}
};

double parallel_pi()
{
  double pi;
  double width = 1./(double)num_steps;

  MyPi step(&width);  //construct MyPi with initializer of step(&width)

  parallel_reduce(blocked_range<size_t>(0,num_steps), step, auto_partitioner());

  pi = step.sum*width;
  return (pi);
}

double serial_pi()
{
  int i;
  double x, sum=0.0, step, pi;
  step = 1.0/num_steps;
  for (i=0; i<num_steps; i++)
    {
      x = (i + .5)*step;
      sum = sum + 4.0/(1.+ x*x);
    }

  pi = sum * step;

  return (pi);
}

int main(int argc, char* argv[])
{
  tick_count before,after;
  double time_parallel,time_serial;
  double pi, pis;
  task_scheduler_init init;

  printf("Approximating pi with %lld rectangles\n\n", num_steps);

// compute serial version of pi
  before = tick_count::now();
  pis = serial_pi();
  after = tick_count::now();
  time_serial = ( after - before ).seconds();

  printf("Serial: The value of PI is %15.12f\n",pis);
  printf("The time to calculate PI was %f seconds\n", time_serial );

// compute parallel version of pi
  before = tick_count::now();
  pi = parallel_pi();
  after = tick_count::now();
  time_parallel = ( after - before ).seconds();

  printf("\nParallel: The value of PI is %15.12f\n",pi);
  printf("The time to calculate PI was %f seconds\n", time_parallel );

  printf("\nSpeedup = = %6.2fX\n\n", time_serial/time_parallel);

  return 0;
}
