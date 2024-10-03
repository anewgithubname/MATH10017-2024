#include <stdio.h>

// write num_factors function below. 
// two inputs, i > j > 1
// one integer output. 
int num_factors(int i, int j){
    int num = 0;
    if( i > j && j > 1){
        if( i % j == 0){
            num = num + 1;
        }
        num = num + num_factors(i,j-1);
    }
    return num; 
}

void main()
{
    // test your num_factors below with different i, j
    printf("%d\n", num_factors(16, 5));

    // print all prime numbers from 1 to 100
    int i = 2; 
    for(i = 2; i < 100; i = i + 1){
        if(num_factors(i, i-1) == 0){
            printf("%d ", i);
        }
    }
    printf("\n");
}