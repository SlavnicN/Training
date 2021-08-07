#include <stdio.h>
#include <stdlib.h>

int arraySearch(int* arr, int n) {
    int i=0;
    int size = sizeof(arr);
    for (i = 0; i < n; i++) {
        if (arr[i]== n) {
            return 1;
        } 
    }
    return 0;
}

int arrSearchDico(int* arr, int n,int pivot,int min ,int max) {
    
    if(arr[pivot]==n) {
        return 1;
    }else if(pivot == min || pivot == max){
        return 0;
    }else if (arr[pivot] > n) {
        return arrSearchDico(arr, n, (pivot-min)/2,min,pivot);
    }else if(arr[pivot] < n){
        return arrSearchDico(arr, n,max - (max-pivot)/2,pivot,max);
    }
}



int main(void) {
    int arr[6] = {1,2,3,4,5,6};
    int size  = sizeof(arr)/sizeof(arr[0]);
    int pivot = size/2;
    int res = arraySearch(arr,9);
    int res2 = arrSearchDico(arr,-1,pivot,0,size);
    printf("%d",res);
    printf("%d",res2);
    return 0;
}