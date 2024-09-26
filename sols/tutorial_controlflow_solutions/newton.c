#include <stdio.h>
#include <math.h>

/*
 * Computes one iteration of Newton's algorithm for finding
 * the square root of a.
 *
 * Given a guess x for the root, it returns the next guess.
 */
double sqrt_iter(double x, double a)
{
  return x/2 + a/(2*x);
}

double find_sqrt(double a)
{
  int niter = 10; // number of iterations
  double x = a; // initial guess is a
  
  for(int i = 0; i < niter; i++){
    x = sqrt_iter(x, a);
  }

  return x;
}

double abs_err(double x, double y)
{
  return fabs(x - y);
}

double rel_err(double x, double y)
{
  if (x > 1E-10)
    return fabs((x-y)/x);
  else
    return 1E10 * abs_err(x,y);
}

double find_sqrt2(double a)
{
  double x0 = a;
  double x1 = sqrt_iter(x0, a);
  double temp;
  double err = 1e-8;

  while(abs_err(x1, x0) > err){
    x0 = x1;
    x1 = sqrt_iter(x1, a);
  }
  return x1;
}

double find_sqrt3(double a)
{
  double x0 = a;
  double x1 = sqrt_iter(x0, a);
  double temp;
  double err = 1e-8;

  while(abs_err(x1, x0) > err || rel_err(x1, x0) > err){
    x0 = x1;
    x1 = sqrt_iter(x1, a);
  }
  return x1;
}


/*
 * Computes one iteration of Newton's algorithm for finding
 * the root of f(x) = 0.
 *
 * Given a guess x for the root, it returns the next guess.
 *
 * The function f and its derivative df must be provided.
 */

double newton_iter(double x, double f(double x), double df(double x))
{
  return x - f(x) / df(x);
}

// x = initial guess, f = function, df = derivative of f
double newton(double x, double f(double x), double df(double x))
{
  int niter = 10; // number of iterations
  
  for(int i = 0; i < niter; i++){
    x = newton_iter(x, f, df);
  }
  return x;
}

//Q: how do we know if we have enough iterations?

double newton2(double x, double f(double x), double df(double x))
{
  double err = 0.0001;
  
  while(f(x) > err || f(x) < -err){
    x = newton_iter(x, f, df);
  }
  return x;
}

// Q: what if f(x) = 0.000001 * (x^3 - 2)? Then this stopping condition is bad.

double cubed(double x)
{
  return x * x * x;
}

// cubic(x) = x^3 - 2
double cubic(double x)
{
  return cubed(x) - 2;
}

double dcubic(double x)
{
  return 3 * x * x;
}


int main()
{
  int n = 2;
  printf("The square root of %d is approximately %.10f.\n", n, find_sqrt2(n));

  double x = 2E-12;
  printf("The square root of %.14f is approximately %.14f.\n", x, find_sqrt2(x));
  printf("The square root of %.14f is approximately %.14f.\n", x, find_sqrt3(x));

  printf("The cubed root of %d is approximately %f.\n", n, newton(n, cubic, dcubic));
  printf("Check: %d = %f.\n", n, cubed(newton(n, cubic, dcubic)));

  printf("The cubed root of %d is approximately %f.\n", n, newton2(n, cubic, dcubic));
  
}

/*
 * Better stopping conditions would use the absolute error between two estimates: |x_n - x_{n-1}|
 * or the relative error between two estimates |x_n - x_{n-1}|/|x_n| to decide if the algorithm
 * should stop.
 *
 * Absolute error is better when the root is large, relative error is better when the root is small.
 * You could check that *both* errors are small.
 *
 * See https://www.math.uakron.edu/~kreider/num1/stopcrit.pdf for a discussion.
 */
