#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h>

typedef struct Node Node;
struct Node{
    int value;
    Node* next;
};

typedef struct Stack Stack;
struct Stack{
    Node* head;
    int len;
};

Node* newNode(int value){
    Node* node = malloc(sizeof(Node));

    if (!node) {
        printf("Heap Overflow\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->next = NULL;

    return node;
}

Stack* initStack(){
    Stack* stack = malloc(sizeof(Stack));
    if (!stack) {
        printf("Heap Overflow\n");
        exit(EXIT_FAILURE);
    }

    stack->head = NULL;
    stack->len = 0;

    return stack;
}

void printStack(Stack* stack){
    Node* node = stack->head;
    for (int i = 0; i<stack->len; i++) {
        printf("Node[%d] = %d\n", i, node->value);
        node = node->next;
    }
    printf("\n");
}

void push(Stack* stack, int value){
   Node* node = newNode(value);

   if(stack->len == 0){
       stack->head = node;
   }else{
       node->next = stack->head;
       stack->head = node;
   }

   stack->len++;
}

int pop(Stack* stack){
    if (stack->len == 0) {
        printf("No Stack \n");
        exit(EXIT_FAILURE);
    }
    Node* tmp = stack->head;
    int value = tmp->value;
    stack->head = tmp->next; 

    stack->len--;
    free(tmp);
    return value;
}

void peek(Stack* stack){
    if(stack->len == 0){
        printf("the stack is empty");
        printf("\n");
    }else{
        printf("the peak: %d", stack->head->value);
        printf("\n");
    }
}

void freeStack(Stack* stack) {
    while (stack->len > 0) {
        pop(stack);
    }
    free(stack);
}

int main(){
    
    Stack* my_stack = initStack();
    push(my_stack, 1);
    push(my_stack, 2);
    printStack(my_stack);
    peek(my_stack);
    int value = pop(my_stack);
    peek(my_stack);
    value = pop(my_stack);
    peek(my_stack);

    return EXIT_SUCCESS; 
}

