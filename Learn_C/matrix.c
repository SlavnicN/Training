#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int i;
    int row, column;
    int n,N;
    int** matrix; 
    scanf("%d", &n);

    N = n*2-1;
    matrix = calloc(N+1,sizeof(int*));
    for(i=1; i<N+1; i++){
        matrix[i] = calloc((N+1),sizeof(int));
    }

    for(row = 1; row<N+1;row++){
        for(column = 1; column<N+1;column++){
            matrix[row][column]=9;
        }
    }
    for(row = 1; row<N+1;row++){
        for(column = row; column<N+2-row;column++){
            matrix[row][column] =abs(n-row)%n+1;
            matrix[N+1-row][column] =abs(n-row)%n+1;
        }
    }

    for(column = 1; column<N+1;column++){
        for(row = column; row<N+2-column;row++){
            matrix[row][column] =abs(n-column)%n+1;
            matrix[row][N+1-column] =abs(n-column)%n+1;
            
        }
    }

    for(row = 1; row<N+1;row++){
        for(column = 1; column<N+1;column++){
            printf("%d ",matrix[row][column]);
        }
        printf("\n");
    }

    for (i = 1; i < N + 1; i++)
    {
        free((void*)matrix[i]);
    }
    free((void*)matrix);
    return 0;
}