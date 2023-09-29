#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h>

void bubble_sort(int * arr, int len){
    for(int i=0; i<len; i++){
        for (int j=0; j<len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main(){
    
    int arr[10] = {1,3,4,7,2,12,2,54,1,0};

    int len = sizeof(arr) / sizeof(arr[0]);

    printf("the arr before:");
    for (int i=0; i<len; i++) { 
        printf("%d ",arr[i]);
    }
    printf("\n");

    bubble_sort(arr, len);


    printf("the arr after:");
    for (int i=0; i<len; i++) { 
        printf("%d ",arr[i]);
    }
    printf("\n");

    return EXIT_SUCCESS; 
}
