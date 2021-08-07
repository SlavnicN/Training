#include <stdlib.h>
#include <stdio.h>  

int main(void){
    char str[] = "abqeoowritv";
    int alpha[128] = {0};
    int i=0;
    int size = sizeof(str);
    int arr[size];
    int tmp=0;
    int isUnique=1;

    for(i=0;i<size-1;i++){
        tmp = str[i]-'a';
        //alpha[tmp]++;
        if (alpha[tmp])
        {
            printf("It's not Unique!");
        }
        alpha[tmp] = 1;
    }
    printf("It's Unique!");

    // for (i = 0; i < 26; i++)
    // {
    //     if(alpha[i] > 1){
    //         isUnique = 0;
    //         break;
    //     }
    // }

    // if (isUnique)
    // {
    //     printf("It's Unique!");
    // }else{ 
    //     printf("It's not Unique!");
    // }
    

}