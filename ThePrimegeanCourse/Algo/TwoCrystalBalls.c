#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int two_crystal_balls(int arr[], int length, int num){
    int jump = floor(sqrt(length));
    int last_good = 0;
    int good = -1;

    for (int i = 0; i < length ; i = i + jump) {
        if (arr[i] == 1) {
            last_good = i - jump;
            break;
        }
    }

    for (int i = last_good; i < last_good + jump ; i++) {
        if (arr[i] == 1) {
            return i-1;
        }
    }
    return -1;
}


int main(){
    int arr[10] = {0,0,0,0,0,1,1,1,1};
    int length = sizeof(arr) / sizeof(arr[0]);

    int res = two_crystal_balls(arr, length, 0);
    
    printf("%d", res);
    return EXIT_SUCCESS; 
}
