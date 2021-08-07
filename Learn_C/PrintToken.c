#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    char *tmp;
    int i=0,j=0;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.

    for(i = 0; i< strlen(s); i++){
        while (s[i] != ' ' && s[i]!='\0'){
            printf("%c",s[i]);
            i++;
        }
        printf("\n");
    }


    for(i = 0; i< strlen(s); i++){
        while (*(s+i) != ' ' && *(s+i)!='\0'){
            printf("%c",*(s+i));
            i++;
        }
        printf("\n");
    }

    free(s);
    return 0;
}