#include <stdio.h>

int steps = 0;

int factorial(int n)
{
  if(n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

int fib(int n)
{
  steps += 1; // keep track of the number of callcs to fib
  if(n == 0)
    return 1;
  else if(n == 1)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main()
{
  printf("10! = %d\n", factorial(10));
  int n = 10;
  printf("The %dth Fibonnaci is %d, this took %d steps.\n", n, fib(n), steps);
  printf("The first %d Fibonnaci numbers are:\n", n);
  for(int i = 1; i <= 10; i++){
    printf("%d ", fib(i));
  }
  printf("\n");
}
