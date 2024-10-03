#include <stdio.h>

// Exercise 0: print header and newline, for test printing
void header(char func_name[]){
  printf("Tests for %s\n", func_name);
}

// Exercise 1: array printing function
void print(int a[], int len){
  ; // YOUR CODE HERE
}

// Exercise 2: sum the elements of an array
int sum(int a[], int len){
  ; // YOUR CODE HERE
}

// Exercise 3: filling arrays

// fill_zeros: set the entries of a[] to 0
void fill_zeros(int a[], int len);

// fill_range: set the entries of a[] to 1, 2, ... , len
// YOUR CODE HERE

// Exercise 4: copy

// Exercise 5: reverse

// Exercise 6: aggregate in place

// Exercise 7: aggregate to new array

// Exercise 8: bad aggregation function

int main(){

  // Test for print
  header("print");
  int arr1[] = {1,2,3,4,5};
  int len1 = 5; // this is clearer than writing the length of arr1 directly
  print(arr1, len1);

  // Test for sum
  header("sum");
  // YOUR CODE HERE: print out the sum of arr1

  // Test for fill_zeros
  header("fill_zeros");
  int arr2[10];
  int len2 = 10;
  // call fill_zeros
  // print the result
  
  // Test for fill_range
  // similar
    
  // Test for copy
  // declare an array int b[len], when len is the length of the array you want to copy
  // copy one of the previous arrays to b, then print the result
    
  // ...and so on
}
