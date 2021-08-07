#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <regex.h>

int main() {

    regex_t regex;
    
    char * num = malloc(1000*sizeof(char));
    int arr[9];
    int i = 0;
    int return_value; 
    return_value = regcomp(&regex,"[0-9]",0);
    if (return_value == 0){
        printf("Regular expression compiled successfully.");
    }
    else{
        printf("Compilation error.");
    }

    for (i = 0; i < 10; i++){
        arr[i] = 0;
    }
    
    scanf("%[^\n]",num);
    i=0;

    while (num[i] != '\0'){
        if(!regexec(&regex, &num[i], 0, NULL, 0)){
            printf("%d\n",(num[i] - '0'));
            arr[(num[i] - '0')]+=1;
        }
        i++;
    }

    
    for (i = 0; i < 10; i++){
        printf("%d",arr[i]);
    }
    
    return 0;
}
