#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h>

bool linear_search(int arr[], int length, int num){
    //int length = sizeof(arr) / sizeof(arr[0]);

    printf("in search arr lenght: %d\n",length);
    for (int i=0; i<length; i++) { 
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]) { 
    int arr[3] = {1,2,3};
    
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Arr length:%d\n",length);

    printf("the arr:");
    for (int i=0; i<length; i++) { 
        printf("%d",arr[i]);
    }
    printf("\n");

    bool res = linear_search(arr, length, 4);

    printf("the res is = %d", res); 
    return EXIT_SUCCESS; 
}
