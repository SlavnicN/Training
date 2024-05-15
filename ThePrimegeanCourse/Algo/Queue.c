#include <stdlib.h> 
#include <stdio.h> 
#include <stdbool.h>

typedef struct Node Node;
struct Node{
    int value;
    Node* next;
};

typedef struct Queue Queue;
struct Queue{
    Node* head;
    Node* tail;
    int len;
};

Node* newNode(int value){

    //TODO Understand why this worked on Linux and not on mac 
    Node *node = malloc(sizeof(Node));

    if (!node) {
        printf("Heap Overflow\n");
        exit(EXIT_FAILURE);
    }

    node->value = value;
    node->next = NULL;

    return node;
}

Queue* initQueue(){
    Queue *my_queue = malloc(sizeof(Queue));

    if (!my_queue) {
        printf("Heap Overflow\n");
        exit(EXIT_FAILURE);
    }

    my_queue->head = NULL;
    my_queue->tail = NULL;
    my_queue->len=0;

    return my_queue;
}

void printQueue(Queue* queue){
    Node* current = queue->head;
    for (int i = 0; i< queue->len; i++) {
        printf("Node[%d] = %d ",i, current->value);
        current = current->next;
    }
    printf("\n");
}

void peek(Queue* queue){
    if(queue->tail != NULL){
        printf("Node = %d ",queue->tail->value);
    }
}

void push(Queue* queue, int value){
    Node *node = newNode(value);

    if(queue->len == 0){
        queue->head = node;
        queue->tail = node;
    }else{
        queue->tail->next = node;
        queue->tail = node;
    }
    queue->len++;
}

int pop(Queue* queue){
    if(queue->head == NULL){
        return -1;
    }

    Node* tmp = queue->head;
    int data = tmp->value;
    queue->len--;
    queue->head = tmp->next;

    free(tmp);
    return data;
}

bool isEmpty(Queue* queue){
    return queue->head == NULL;
}

int main(){
    //This is allocated on the stack, they will be gone when out the
    //function main()
    //malloc() will allocated them on the heap, making them persistante outside
    //of the main()malloc, but need to free them manually
    //Another probleme is size limit, the stack is smaller than the heap
    //so if there is a lot of recursive call on the stack it might break 
    //
    //
    Queue *my_queue = initQueue();

    push(my_queue, 1);
    push(my_queue, 2);
    printQueue(my_queue);
    pop(my_queue);
    printQueue(my_queue);
    peek(my_queue);

    free(my_queue);

    return EXIT_SUCCESS; 
}

