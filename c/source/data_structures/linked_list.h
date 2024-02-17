#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{
    int value;
    struct node *link;
}node;

typedef enum{
    false = 0,
    true = 1
}bool;


#if !defined(RANGE)
#define MAX 100000000
#define MIN -100000000
#define RANGE MAX - MIN + 1
#endif // RANGE

void fill_linkedlist(node **head, int size);
void print_linkedlist(node **head);
void freeall(node **head);


void fill_linkedlist(node **head, int size){
    srand((unsigned int)time(NULL));
    node *temp;
    for (int i = 0; i < size; i++){
        if (i == 0)
            (*head)->value = rand() % RANGE + MIN;
        temp = (node*)malloc(sizeof(node));
        temp->value = rand() % RANGE + MIN;
        temp->link = *head;
        *head = temp;
    }
}


void print_linkedlist(node **head){ // improve printing later
    system("clear");
    node *temp = *head;
    while (temp != NULL){
        printf("%d->", temp->value);
        temp = temp->link;
    }
    printf("null\n");
}


void freeall(node **head){
    node *temp = *head, *prev;
    while (temp != NULL){
        prev = temp;
        temp = temp->link;
        free(prev);
    }
}