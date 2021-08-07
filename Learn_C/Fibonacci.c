#include <stdlib.h>
#include <stdio.h>

int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }else if (n == 1) {
        return 1;
    }else {
        return Fibonacci(n-1) + Fibonacci(n -2);
    }
}
int fibonacciArr(int n) {
    if (n == 0) return 0;
    int fn_1 = 0;
    int fn_2 = 1;
    int i = 0;
    int fn = 0;
    for (i = 2; i <= n; i++) {
        // a + b = f3
        // a = f3
        // a + b = f4
        // b = f4
        fn = fn_1+fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn_1 + fn_2;
}
int main(void) {
    FILE *filepointer;
    int res=0;
    res = Fibonacci(14);
    // filepointer = fopen("fibo.txt","w+");
    // if (filepointer != NULL) {
    //     fputc((char)res,filepointer);
    // }
    // char c = fgetc(filepointer);
    // printf("%c",c);
    // fclose(filepointer);
    printf("%d \n", fibonacciArr(15));
    printf("%d", Fibonacci(15));

    return 0;
}