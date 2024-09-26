#include <stdio.h>
#include <math.h>

/*
 * We will use the identity
 * sin(x) = 3*sin(x/3) - 4*sin^3(x/3)
 * to recursively replace sin(x) with sin(x/3)
 *
 * If x is small enough, we will return sin(x) = x
*/

double cube(double x){
  return x * x * x;
}

double sine(double x){
  if(x < 0.001)
    return x;
  else {
    return 3 * sine(x/3) - 4 * cube(sine(x/3));
  }
}

/*
 * NEWTON'S METHOD
 *
 * Newton's method is an iterative algorithm for finding roots of equations.
*/



int main(){
  double x = 1.3;
  printf("We calculate sin(%f) = %f.\n", x, sine(x));
  printf("C calculates sin(%f) = %f.\n", x, sin(x));
}
