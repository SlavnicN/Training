#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <math.h>

bool binary_search(int arr[], int len, int n){
    int m = 0;
    int lo = 0;
    int hi = len;

    do {

        m = abs(lo + (hi - lo)/2);

        if (arr[m] == n) {
            return true; 
        }else if (arr[m]<n) {
            lo = m+1; 
        }else {
            hi = m;
        }

        printf("m=%d\n",m);

    }while (lo<hi);

    return false;
}

int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int res = binary_search(arr,10, 1);
    
    printf("res = %d", res);

    return EXIT_SUCCESS;
}
