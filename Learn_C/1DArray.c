#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int* array;
    int n,i,res=0;
    scanf("%d", &n);
    array = calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        res += array[i];
    }
    printf("%d", res);
    return 0;
}