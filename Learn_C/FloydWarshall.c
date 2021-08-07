#include <stdio.h>
#include <stdlib.h>
#define INF 99999

int** matrixAdj;

int min(int a, int b) {
    if (a<b) {
        return a;
    }
    return b;
}

void printMatrixAdj(int n) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j= 0; j < n; j++) {
            if (matrixAdj[i][j] == INF) {
                printf("x ");
            }else {
                printf("%d ", matrixAdj[i][j]);
            }   
        }
        printf("\n");
    }
}

void createMatrixAdj(int arr[][3], int n, int m) {
    int i,j ;
    matrixAdj = malloc(n*sizeof(int*));
    for (i = 0; i < n; i++) {
        matrixAdj[i] = malloc(n*sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j= 0; j < n; j++) {
            matrixAdj[i][j] = INF; 
        }
    }

    for (i = 0; i < m; i++) {
        matrixAdj[arr[i][0]][arr[i][1]] = arr[i][2]; 
        //matrixAdj[arr[i][1]][arr[i][0]] = 1; 
    }
}

void floydWarshall(int n) {
    int i,j,k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j) {
                    matrixAdj[i][j] = 0;
                }
                if (matrixAdj[i][j] != INF && matrixAdj[i][k]!= INF && matrixAdj[k][j]!= INF) {
                    matrixAdj[i][j] = min(matrixAdj[i][j],matrixAdj[i][k] + matrixAdj[k][j]);
                }
            } 
        }
    } 
}

int main(void) {
    //N = 5, M = 4, arr[][] = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 5 } }
    int n = 5, m=5;
    int arr[5][3] = { { 2, 1, 4}, { 1, 3 , -2}, { 3, 4 , 2 }, { 4, 2 , -1}, { 2, 3 , 3} };
    //int n = 4, m=4;
    //int arr[4][3] = { { 0, 3, 10}, { 2, 3 , 1}, { 1, 2 , 3 }, {0, 1, 5} };
    int i,j;

    createMatrixAdj(arr, n, m);
    printMatrixAdj(n);
    floydWarshall(n);
    printf("\n");
    printMatrixAdj(n);
    
    
    for (i = 0; i < n; i++){
       free(matrixAdj[i]);
    }
    free(matrixAdj);
    
    return 0;
}
