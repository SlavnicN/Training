#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTree();

int main(){

    LinkedList* mylist = initLL();
    prepend(mylist, 3);
    prepend(mylist, 4);
    append(mylist, 5);
    insertAt(mylist, 8, 2);
    printLL(mylist);
    printf("get = %d\n", get(mylist, 2));

    removeOf(mylist, 4);
    removeAt(mylist, 0);

    printLL(mylist);

    return EXIT_SUCCESS;
}
