#include <stdio.h>

/*
 * Define f by f(n) = n if n < 3 and
 * f(n) = f(n - 1) + 2f(n - 2) + 3f(n - 3) if n >= 3.
 * 
 * Write a function to compute f recursively.
 *
 * Write a function to compute f using loops and "state" variables
 * that keep track of f(n-1), f(n-2), and f(n-3).
 */
int f(int n){
  if (n < 3)
    return n;
  else
    return f(n - 1) + 2*f(n - 2) + 3*f(n - 3);
}

int f_loop(int n){
  if (n < 3)
    return n;
  
  int f0 = 0, f1 = 1, f2 = 2;
  for(int i = 0; i < n; i = i + 1){
    int temp1 = f2, temp2 = f1;
    f2 = f2 + 2*f1 + 3*f0;
    f1 = temp1;
    f0 = temp2;
  }
  return f0;
}

/*
 * Compute elements of Pascal's triangle by recursion
 *
 *     1
 *    1 1
 *   1 2 1
 *  1 3 3 1
 * 1 4 6 4 1
 *
 * The numbers at the edge of the triangle are all 1, and each number
 * inside the triangle is the sum of the two numbers above it.
 *
 * Let n denote the row of the triangle and let 0<= k <= n denote the kth
 * number in row n.
 *
 * n starts at 0.
 * 
 */
int pascal(int n, int k){
  if (k == 0 || k == n)
    return 1;
  else
    return pascal(n - 1, k) + pascal(n - 1, k - 1);
}

void print_pascals_triangle(int N){
  for(int n = 0; n <= N; n++){
    for(int j = 0; j < N - n; j++){printf("  ");} // print N - n spaces
    for(int k = 0; k <= n; k++){
      printf("%3d ", pascal(n, k));
    }
    printf("\n"); 
  }
}


int main(){
  int n = 8;
  printf("The value of f(%d) is %d.\n", n, f(n));
  printf("The value of f(%d) is %d.\n", n, f_loop(n));

  // print Pascal's triangle
  int N = 5;
  print_pascals_triangle(N);
}
