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

void printQueue(Node* head, int n){
    for (int i = 0; i<n; i++) {
        printf("Node[%d] = %d ",i, head->next->value);
        head = head->next;
    }
    printf("\n");
}

void push(Node* A, Node* tail){
    tail->next->next = A;
    tail->next = A;
}

int pop(Node* head){
    Node* tmp = head->next;
    head->next = tmp->next;
    tmp->next = NULL;

    return tmp->value;
}

int main(){
    
    Node head;
    Node tail;
    Queue my_queue;

    my_queue.head = &head;
    my_queue.tail = &tail;

    Node A;
    Node B;
    Node C;
    Node D;
    Node F;
    head.next = &A;
    tail.next = &B;

    A.value = 1;
    A.next = &B;
    B.value = 2;
    C.value = 3;
    D.value = 4;
    F.value = 5;

    push(&C, &tail);
    push(&D, &tail);
    push(&F, &tail);

    pop(&head);

    printf("new tail: %d", tail.next->value);
    printQueue(&head, 5);
    
    return EXIT_SUCCESS; 
}

