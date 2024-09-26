#include <stdio.h>

int factorial_loop(int n)
{
  int result = 1;
  
  for(int i = 1; i <= n; i++)
    result *= i;
  
  return result;
}

int factorial_loop2(int n)
{
  int result = 1;
  
  while(n > 0)
    result *= n--;
  
  return result;
}

int factorial_iter(int product, int count, int max_count)
{
  if(count > max_count)
    return product;
  else
    return factorial_iter(product * count, count + 1, max_count);
}

int factorial(int n)
{
  return factorial_iter(1, 1, n);
}

int fib_loop(int n)
{
  int a = 1, b = 0;
  int temp;

  while(n-- > 0) {
    temp = b;
    b = a;
    a = b + temp;
  }
  return b;
}

int fib_loop2(int n)
{
  int a = 1, b = 0;
  int temp;

  for(int i = 0; i < n; i++){
    temp = b;
    b = a;
    a = b + temp;
  }
  return b;
}

int main()
{
  int n = 10;
  printf(" %d! = %d (or %d, or %d).\n", n, factorial_loop(n), factorial_loop2(n), factorial(n));
  printf("The %dth Fibonnaci number is %d (or %d).\n", n, fib_loop(n), fib_loop2(n));
}
