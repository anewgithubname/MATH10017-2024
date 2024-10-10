#include <stdio.h>

// helper: print_arr
void print_arr(int a[], int len){
  for(int i = 0; i < len; i++){
    printf("%d ", a[i]);
    if(i >= 80 && i % 80 == 0)
      printf("\n");
  }
  printf("\n");
}


// reverse an array
void reverse(int a[], int len){
  int temp;
  for(int i = 0; i < len/2; i++){
    temp = a[len - i - 1];
    a[len - i - 1] = a[i];
    a[i] = temp;
  }
}

// aggregate in place
void agg_in_place(int a[], int len){
  for(int i = 1; i < len; i++){
    a[i] += a[i - 1];
  }
}

// copy
void copy(int a[], int b[], int len){
  for(int i = 0; i < len; i++)
    b[i] = a[i];
}

// bad copy
void bad_copy(int a[], int b[]){
  b = a;
}

/*
 * store aggregate in second array
 *
 * Hint: use copy and agg_in_place to make
 */
void agg(int a[], int b[], int len){
  copy(a, b, len);
  agg_in_place(b, len);
}

// sum
int arr_sum(int a[], int len){
  int result = 0;
  for(int i = 0; i < len; i++)
    result += a[i];
  return result;
}

// fill zeros
void fill_zeros(int a[], int len){
  for(int i = 0; i < len; i++)
    a[i] = 0;
}

// fill 1,2,3,...  (good exercise... make sure they know array starts at 0
void fill_range(int a[], int len){
  for(int i = 0; i < len; i++)
    a[i] = i + 1;
}

// print row i of matrix stored as row major array
void print_row(int m[], int nrow, int ncol, int i){
  for(int j = 0; j < ncol; j++){
    printf("%2d ", m[i*ncol + j]);
  }
  printf("\n");
}

void print(int m[], int nrow, int ncol){
  for(int i = 0; i < nrow; i++)
    print_row(m, nrow, ncol, i);
}

// print column j of matrix stored as row major arry
void print_col(int m[], int nrow, int ncol, int j){
  for(int i = 0; i < nrow; i++){
    printf("%2d ", m[i*ncol + j]);
  }
  printf("\n");
}

/*
 * matrix operations
 */
// sum rows
// m = nrow x ncol matrix stored in row major form
// row_sums = array of 0's
void sum_rows(int m[], int nrow, int ncol, int row_sums[]){
  for(int i = 0; i < nrow*ncol; i++)
    row_sums[i / ncol] += m[i];
}

void sum_cols(int m[], int nrow, int ncol, int col_sums[]){
  for(int i = 0; i < nrow * ncol; i++)
    col_sums[i % ncol] += m[i];
}

int main(){
  int arr1[] = {1,2,3,4,5,6};
  int arr2[] = {1,3,5,7,9};
  int len1 = 6, len2 = 5;
  
  print_arr(arr1, 6);
  print_arr(arr2, 5);  

  // test reverse
  reverse(arr1, 6);
  reverse(arr2, 5);
  
  print_arr(arr1, 6);
  print_arr(arr2, 5);

  // test agg_in_place
  int arr3[] = {1,4,9,16,25,36};
  int len3 = 6;
  print_arr(arr3, len3);
  agg_in_place(arr3, len3);
  print_arr(arr3, len3);

  // test copy
  int arr4[] = {1,4,9,16,25,36};
  int len4 = 6;
  int arr4_copy[len4];
  copy(arr4, arr4_copy, len4);
  print_arr(arr4_copy, len4);

  // test bad copy
  printf("Test for bad_copy:\n");
  int arr4_bad_copy[len4];
  bad_copy(arr4, arr4_bad_copy);
  print_arr(arr4_bad_copy, len4);

  /*
   * What did you expect to happen? What actually happened?
   */

  // test agg
  int arr5[] = {1,2,3,4,5,6};
  int len5 = 6;
  int arr5_agg[len5];
  agg(arr5, arr5_agg, len5);
  print_arr(arr5, len5);
  print_arr(arr5_agg, len5);

  // test matrix functions
  printf("\nTest matrix functions\n\n");
  int nrow = 3, ncol = 4;
  int m[nrow * ncol];
  fill_range(m, nrow * ncol);
  print(m, nrow, ncol);
  printf("\n");
  print_row(m, nrow, ncol, 2);
  print_col(m, nrow, ncol, 2);
  int row_sums[nrow], col_sums[ncol];
  fill_zeros(row_sums, nrow);
  fill_zeros(col_sums, ncol);
  sum_rows(m, nrow, ncol, row_sums);
  sum_cols(m, nrow, ncol, col_sums);
  print_arr(row_sums, nrow);
  print_arr(col_sums, ncol);
}
