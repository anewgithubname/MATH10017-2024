#include <stdio.h>

double ap_sum(double a, double b, double next, double f(double))
{
  double total = 0.0;
  for(double i = a; i <= b; i += next){
    total += f(i);
  }
  return total;
}

double sum(int a, int b, double f(double))
{
  return ap_sum(a, b, 1, f);
}

double left_riemann(double a, double b, int n, double f(double))
{
  double delta = (b - a) / n;
  return ap_sum(a, b - delta, delta, f) / n;
}

double right_riemann(double a, double b, int n, double f(double))
{
  double delta = (b - a) / n;
  return ap_sum(a + delta, b + delta/2, delta, f) / n;  
}
		     

double square(double i)
{
  return i * i;
}

int main()
{
  int n = 100;
  printf("The sum from i = 1 to 10 of i^2 is %.0f.\n", sum(1, 10, square));
  printf("Approximating the integral of f(x) = x^2 from 0 to 1:\n");
  printf("Left Riemann sum with %d terms:  %f.\n", n, left_riemann(0, 1, n, square));
  printf("True area: %f.\n", 1.0/3);
  printf("Right Riemann sum with %d terms:  %f.\n", n, right_riemann(0, 1, n, square));
  return 0;
}
