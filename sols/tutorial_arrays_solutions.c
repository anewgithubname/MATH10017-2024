#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// PART 1: FINDING EXTREME VALUES
//
//


int find_max(int arr[], int len){
  int max = arr[0]; // largest value seen so far
  for(int i = 0; i < len; i++){
    if(arr[i] > max){
      max = arr[i]; 
    }
  }
  return max;
}


int find_min(int arr[], int len){
  int min = arr[0]; // smallest value seen so far
  for(int i = 0; i < len; i++){
    if(arr[i] < min){
      min = arr[i]; 
    }
  }
  return min;
}

int find_second_smallest(int arr[], int len){
  int min1, min2; // min1 = smallest, min2 = second smallest
  if(arr[0] <= arr[1]){
    min1 = arr[0];
    min2 = arr[1];
  }
  else{
    min1 = arr[1];
    min2 = arr[0];
  }
  for(int i = 1; i < len; i++){
    if(arr[i] < min1){
      min2 = min1; // old min1 value is now second smallest
      min1 = arr[i]; 
    }
    else if (arr[i] < min2){
        min2 = arr[i];
    }
  }
  return min2;
}

////////////////////////////////////////////////////
// ALTERNATIVE VERSION OF FIND SECOND SMALLEST
////////////////////////////////////////////////////

/*
 * find_smallest_index: return the index of the smallest element in arr
 */
int find_smallest_index(int arr[], int len){
  int min_val = arr[0]; // smallest value seen so far
  int min_idx = 0; // smallest index seen so far
  for(int i = 0; i < len; i++){
    if(arr[i] < min_val){
      min_val = arr[i];
      min_idx = i;
    }
  }
  return min_idx;
}

/*
 * find_second_smallest2: return second smallest value in array
 *
 * Note: to avoid modifying the input array, we store the minimum value
 * before changing it to INT_MAX so we can restore it after finding
 * the second smallest value. If you do not need to reuse the array,
 * you can skip this step.
 */
int find_second_smallest2(int arr[], int len){
  int min_idx = find_smallest_index(arr, len);
  int min_val = arr[min_idx]; // store smallest value
  arr[min_idx] = INT_MAX; // change min value to largest possible value
  int second_smallest_val = find_min(arr, len);
  arr[min_idx] = min_val; // restore smallest value
  return second_smallest_val;
}

// PART 2: GET ROW
//
//


// BASIC VECTOR AND MATRIX CODE
struct vector {
  int len;
  int *elements;
};
typedef struct vector Vector; // use 'Vector' as an alias for 'struct vector'

void print_vec(Vector v){
  for(int i = 0; i < v.len; i++)
    printf("%d ", v.elements[i]);
  printf("\n");
}

struct matrix {
  int nrow;
  int ncol;
  int *elements;
};
typedef struct matrix Matrix;

/*
 * idx: return (flattened) index of i,j element of row-major matrix M
 */
int idx(Matrix M, int i, int j){
  return i * M.ncol + j;
}

int get_elem(Matrix M, int i, int j){
  return M.elements[idx(M, i, j)];
}

void set_elem(Matrix M, int i, int j, int val){
  M.elements[idx(M, i, j)] = val;
}

void print_mat(Matrix M){
  for(int i = 0; i < M.nrow; i++){
    for(int j = 0; j < M.ncol; j++){
      printf("%d ", get_elem(M, i, j));
    }
    printf("\n");
  }
}
// END OF BASIC VECTOR AND MATRIX CODE


/*
 * get_row: return a vector whose elements are the i-th row of Matrix M
 *
 * Note: this returns a *view* of the i-th row of M.
 * - Modifying this vector will modify M as well.
 * - Do not free the memory pointed to by v.elements
 */
Vector get_row(Matrix M, int i){
  Vector v;
  v.len = M.ncol; // length of row vector = # of columns
  v.elements = M.elements + i * M.ncol; // pointer to first element of i-th row
  return v;
}

/*
 * print_mat2: print a row-major matrix using get_row and print_vec
 */
void print_mat2(Matrix M){
  for(int i = 0; i < M.nrow; i++){
    print_vec(get_row(M, i)); // print i-th row of M
  }
}

/*
 * get_col: return a vector whose elements are the j-th column of Matrix M
 *
 * Note: this returns a *copy* of the j-th column of M.
 * - Modifying this vector will *not* modify M, and changes to M will not modify the vector.
 * - You *should* free the heap memory pointed to by v.elements
 */

Vector get_col(Matrix M, int j){
  Vector v = {M.nrow, malloc(M.nrow * sizeof(int))}; // length of column vector = number of rows
  // copy the elements of column j to v.elements
  for(int i = 0; i < M.nrow; i++){
    v.elements[i] = get_elem(M, i, j);
  }
  return v;
}

/*
 * copy_col:
 * copies the elements of the j-th column of Matrix M
 * to the elements of Vector v
 *
 * Vector v: must have the correct length and have memory allocated.
 */
void copy_col(Matrix M, int j, Vector v){
  for(int i = 0; i < M.nrow; i++){
    v.elements[i] = get_elem(M, i, j);
  }
}


// HELPER FUNCTIONS
void print_arr(int arr[], int len){
  for(int i = 0; i < len; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void test_header(char s[]){
  printf("\nTESTING FOR %s\n", s);
}

void test_max(int arr[], int len, int i){
  printf("\nTest for arr%d\n", i);
  print_arr(arr, len);
  printf("max value = %d\n", find_max(arr, len));
}

void test_min(int arr[], int len, int i){
  printf("\nTest for arr%d\n", i);
  print_arr(arr, len);
  printf("min value = %d\n", find_min(arr, len));
}

void test_second_smallest(int arr[], int len, int i){
  printf("\nTest for arr%d\n", i);
  print_arr(arr, len);
  printf("second smallest value = %d\n", find_second_smallest(arr, len));
}


int main(){
  ////////////////////////////////
  // PART 1
  ////////////////////////////////

  // CREATE TEST ARRAYS
  int arr1[] = {1,2,3,4,5};
  int len1 = 5;
  int arr2[] = {1,3,2,4,3}; // DEFINE ARRAY WITH REPEATED MAX AND MIN VALUES
  int len2 = 5;
  int arr3[] = {-100, -99, 0, 234}; // DEFINE ARRAY WITH POSITIVE AND NEGATIVE NUMBERS
  int len3 = 4;
  int arr4[] = {0};
  int len4 = 1;
  
  // TEST FIND MAX AND FIND MIN
  test_header("find_max");
  test_max(arr1, len1, 1);
  test_max(arr2, len2, 2);
  test_max(arr3, len3, 3);
  test_max(arr4, len4, 4);
  
  test_header("find_min");
  test_min(arr1, len1, 1);
  test_min(arr2, len2, 2);
  test_min(arr3, len3, 3);
  test_min(arr4, len4, 4);

  // TEST FIND SECOND SMALLEST
  test_header("find_second_smallest");
  test_second_smallest(arr1, len1, 1);
  test_second_smallest(arr2, len2, 2);
  test_second_smallest(arr3, len3, 3);
  test_second_smallest(arr4, len4, 4);

  ////////////////////////////////
  // PART 2
  ////////////////////////////////
  
  // CREATE A TEST MATRIX
  test_header("print_mat2");
  int elem[] = {1,2,3,4,5,6};
  Matrix mat = {2, 3, elem}; // 2x3 matrix
  print_mat2(mat);
  // TEST GET ROW
  test_header("get_row");
  Vector row0 = get_row(mat, 0);
  printf("The 0-th row is ");
  print_vec(row0);
  
  // TEST: MODIFYING ROW MODIFIES MATRIX
  printf("\nModifying row0 modifies mat:\n");
  printf("setting row0.elements[0] = 10 yields row0 = ");
  row0.elements[0] = 10;
  print_vec(row0);
  printf("\nThe 0th element of row 0 of mat is also changed:\n");
  print_mat2(mat);
  
  // TESTING GET_COL
  test_header("get_col");
  Vector col1 = get_col(mat, 1);
  printf("the 1st column of mat is ");
  print_vec(col1);
  printf("(remember the column index starts at 0)\n");
  printf("\n Modifying col1 doesn't modify mat:\nIf we set col1.elements[0] = 99, mat is not changed.\n");
  col1.elements[0] = 99;
  printf("col1 = ");
  print_vec(col1);
  printf("mat =\n");
  print_mat2(mat);
  free(col1.elements); // don't forget to free heap memory!
  
}
