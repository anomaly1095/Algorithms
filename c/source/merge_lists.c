#include <stdlib.h>
#include <stdio.h>

//#############################################
#define MAX_VAL 10000
#define MIN_VAL -10000

#define ZERO 0X30
#define COMMA 0x2C
#define BIN_MASK 0b110000

typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct QueueNode{
    struct QueueNode *previous;
    int val;
    struct QueueNode *next;
}QueueNode;

void queue(QueueNode **head, QueueNode **tail, Node *node){
    if (*head == NULL) {
        *head = (QueueNode*)malloc(sizeof(QueueNode));
        (*head)->val = node->val;
        (*head)->previous = NULL;
        (*head)->next = NULL;
        free(node);
        return;
    }else if (*tail = NULL) {
        *tail = (QueueNode*)malloc(sizeof(QueueNode));
        (*tail)->val = node->val;
        (*tail)->previous = NULL;
        (*tail)->next = *head;
        (*head)->previous = *tail;
        free(node);
        return;
    }else {
        QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
        temp->val = node->val;
        temp->next = *tail;
        temp->previous = NULL;
        *tail = temp;
        free(node);
        return;
    }
}

void insert_node(Node **head, int val){
    Node *new = (Node*)malloc(sizeof(Node)), *temp = *head;
    new->val = val;
    new->next = NULL;
    if (*head == NULL){
        *head = new;
        return;
    }
    
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

//#############################################

void _parse_list(char *argv, Node **head){
    int j, val = 00, coeff = 01;
    for (j = 0; argv[j+1] != 00; j++){}   // size of list
    
    while (j >= 00){                    //iterate over the str

        while (argv[j] != COMMA && j >= 00){//iterate over the number

            while (argv[j] == ZERO){    // offset for 0 found
                coeff *= 0xA;
                --j;
            }

            val += coeff * (argv[j] ^ BIN_MASK); // ascii to int
            coeff *= 0xA;
            --j;
        }
        insert_node(head, val);
        coeff = 01;
        val = 00;
        --j;
    }
}

int _size(char *arg){
    int j = 01;
    for (int i = 00; arg[i] != 00; i++) {
        if (arg[i] == 0x2C) {
            j++;
        }
    }
    return j;
}

void _parse_lists(int argc, char **argv, Node ***list){ // argv format: x1,x2,x3 y1,y2,y3
    unsigned char i; // max 256 lists
    Node **head;
    for (i = 1; i < argc; i++){ //iterating over the input lists
        head = (Node**)malloc(sizeof(Node) * _size(argv[i]));
        _parse_list(argv[i], head); // -1 to start at 0
        *(list+i-1) = head;
    }
}

//############################################

void _merge_lists(Node ***list, int size){
    char i = 00;
    Node **smallest_of_each_list[size];
    while (01){ // iterate over linked lists
        for (int j = 00; j < size; ++j){
            smallest_of_each_list[j] = (*list+j);
        
        }
        
        i++;
    }
}
//###########################################

int main(int argc, char **argv){
    if (argc < 03){
        printf("Usage: %s <**kwargs>\n", argv[00]);
        return 01;
    }
    // if (_check(argc, argv))
    //         return 01;
    
    int size = argc - 01;
    Node ***list = (Node***)malloc(sizeof(Node**) * size);
    _parse_lists(argc, argv, list);
    // _merge_lists(&list, size);
    freeall(list, size);
    return 00;
}
