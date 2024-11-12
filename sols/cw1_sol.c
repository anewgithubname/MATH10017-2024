#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int D55[] ={2621395, 3452383, 2707358, 2930347, 3452312, 
            3196411, 4339716, 3052141, 1870891, 3692102, 
            2795421, 4821229, 2908232, 4824436, 2047722, 
            3264523, 4025078, 1454067, 4773042, 3153700, 
            2927286, 4281658, 3028798, 3641930, 3273735};

struct matrix
{
    int numrow;
    int numcol;
    int *elements;
};

typedef struct matrix Matrix;

/*
Print an image to the console. 
image: an array stores the flattened image stored in row major order.
Height: the height of the image.
Width: the width of the image.

See lec 7, how images are stored in computers
ctrl + click to open the link
https://github.com/anewgithubname/MATH10017-2024/blob/main/lecs/lec7.pdf
*/
void image2char(int image[], int Height, int Width)
{   
    for(int i = 0; i < Height; i++){ // loop over each row of the image
        for(int j = 0; j < Width; j++){ // loop over each column of the image
            if( image[i*Width + j] < 85){
                printf(" ");
            }
            else if(image[i*Width + j] <170){
                printf("I");
            }else{
                printf("M");
            }
        }
        printf("\n");
    }
}

/*
Read a matrix from file. Don't change it!
filename: the file that contains the matrix.
return: a matrix structure containing the matrix.
*/
Matrix read_matrix(char *filename)
{
    FILE *f = fopen(filename, "rb");
    // read int variables to the file.
    int numrow = getw(f);
    int numcol = getw(f);
    Matrix M = {numrow, numcol, calloc(numrow * numcol, sizeof(int))};

    for (int i = 0; i < M.numrow; i++)
    {
        for (int j = 0; j < M.numcol; j++)
        {
            M.elements[i*numcol + j] = getw(f);
        }
    }

    fclose(f);
    return M;
}

/*
Retrieve an element from a matrix.
M: the matrix, in row major order.
i,j: the row and column of the element, 0-indexed.
return: the element at row i and column j.
*/
int get_elem(Matrix M, int i, int j)
{
    //TODO: your code here.
    return M.elements[i*M.numcol + j];
}

/*
Assign value to an element in a matrix.
M: the matrix, in row major order.
i,j: the row and column of the element, 0-indexed.
value: the value to be assigned.
*/
void set_elem(Matrix M, int i, int j, int value)
{
    //TODO: your code here.
    M.elements[i*M.numcol + j] = value;
}

// Part II
/*
Compute the pairwise distance D between two matrices A and B, 
where D[i][j] is the Euclidean distance between the ith row of A and the jth row of B over **non-corrputed columns**.

A: a matrix of size N x M^2.
B: a matrix of size L x M^2.
D: a matrix of size N x L.
*/
void pairwise_dist(Matrix A, Matrix B, Matrix D){
    for (int i = 0; i < A.numrow; i++){ // for each A_i 
        for (int j = 0; j < B.numrow; j++){ // for each B_j
            int sum = 0;
            for (int k = 0; k < A.numcol; k++){
                if(get_elem(A, i, k) > 255 || get_elem(A, i, k) < 0){ 
                    continue; // skip corrupted columns
                }
                sum += (get_elem(A, i, k) - get_elem(B, j, k)) * (get_elem(A, i, k) - get_elem(B, j, k)); // compute the square of the difference
            }
            set_elem(D, i, j, sum);
        }
    }
}

/*
Find the index of the smallest element in an array.
a: an array of integers.
len: the length of the array.
*/
int find_smallest_idx(int a[], int len){
    // TODO: your code here.
    int min = INT_MAX;
    int idx = -1;
    for (int i = 0; i < len; i++){
        if (a[i] < min){
            min = a[i];
            idx = i;
        }
    }
    return idx;
}

/*
Find the indices of the 5 smallest elements in an array.
a: an array of integers.
len: the length of the array.
idx: an array of integers to store the indices of the 5 smallest elements.
*/
void minimum5(int a[], int len, int idx[]){
    // TODO: your code here. 
    for (int i = 0; i < 5; i++){
        int minid = find_smallest_idx(a, len);
        a[minid] = INT_MAX;
        idx[i] = minid;
    }
}

// checking whether the matrix D you get is correct or not, do not modify.
// no output means OK.
void check(struct matrix D){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (get_elem(D, i, j) != D55[i*5 + j]){
                printf("D[%d][%d] = %d, expected %d\n", i, j, get_elem(D, i, j), D55[i*5 + j]);
                printf("check your pairwisedist function\n");
            }
        }
        printf("\n");
    }
}

void main()
{
    Matrix X = read_matrix("./X.matrix");
    printf("N: %d, M: %d\n", X.numrow, (int) sqrt(X.numcol));   

    Matrix T = read_matrix("./T.matrix");
    printf("L: %d\n", T.numrow);
    
    // print out the first 5 images in X
    printf("\n\nBelow are five corrupted images:\n\n");    
    /*
     Plot the first 5 images in X.
    */
    for (int i = 0; i < 5; i++){
        image2char(X.elements + i*X.numcol, 28, 28);
        printf("\n");
    }

    /* 
     Compute matrix D from X and T.
    */
    Matrix D = {X.numrow, T.numrow, calloc(T.numrow * X.numrow, sizeof(int))};
    pairwise_dist(X, T, D);
    check(D); //for TA use. 

    /*
      for each row in X, restore the corrupted columns using k-nearest neighbours. 
    */
    for (int i = 0; i < X.numrow; i++){ // for each row in X
        int *Di = calloc(T.numrow, sizeof(int)); // store the distances between X_i and each row in T
        for (int j = 0; j < T.numrow; j++){
            Di[j] = get_elem(D, i, j);
        }
        int idx[5];
        minimum5(Di, T.numrow, idx); // find the indices of the 5 smallest elements in Di
        free(Di);

        for (int j = 0; j < X.numcol; j++){
            if (get_elem(X, i, j) <= 255 && get_elem(X, i, j) >= 0){ // skip UNCORRUPTED columns
                continue;
            }
            float sum = 0;
            for (int k = 0; k < 5; k++){
                sum += get_elem(T, idx[k], j);
            }
            set_elem(X, i, j, sum/5); // restore the corrupted column with the average of the 5 nearest neighbours
        }
    }

    printf("\n\nBelow are five corrupted images:\n\n");    
    // plot the first 5 images in X after restoration.
    for (int i = 0; i < 5; i++){
        image2char(X.elements + i*X.numcol, 28, 28);
        printf("\n");
    }

    free(D.elements);
    free(X.elements);
    free(T.elements);
}