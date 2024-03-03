#include <stdio.h>
#include <stdlib.h>
            
            // Program to insert the fast inverse square root in the linked list
//####################################

#define int32 int

// link node
typedef struct Node{
    int32 val;
    struct Node *link;
}Node;

// add node in linked list
void add_node(Node **head, int32 val){
    if (*head == NULL){
        *head = (Node*)malloc(sizeof(Node));
        (*head)->link = NULL;
        (*head)->val = val;
    }else {
        Node *new = (Node*)malloc(sizeof(Node)), *temp = *head;
        while (temp->link != NULL){
            temp = temp->link;
        }
        new->val = val;
        new->link = NULL;
        temp->link = new;
    }
}

// insert node at position
void insert_node(Node **head, int32 val, char pos){
    Node *temp = *head, *new = (Node*)malloc(sizeof(Node));
    char i = 00;
    while (temp->link != NULL){
        temp = temp->link;
        ++i;
        if (i == pos){
            new->val = val;
            new->link = temp->link;
            temp->link = new;
        }
    }
    printf("\n");
}

// free all nodes
void print_list(Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf("%d->", temp->val);
        temp = temp->link;
    }
    printf("null\n");
}

// free all nodes
void free_nodes(Node **head){
    Node *temp = *head, *fr;
    while (temp != NULL){
        fr = temp;
        temp = temp->link;
        free(fr);
    }
}

int32 _m_atoi(char *arr){
    char i;
    int32 val = 00, coeff = 01;
    for (i = 0; arr[i+1] != 00; ++i){}
    while (i >= 00){
        while (arr[i] == 0x30){
            coeff *= 0xA;
            --i;
        }
        val += coeff * (arr[i] ^ 0b110000);
        --i;
        coeff *= 0xA;
    }
    return val;
}

//####################################

int main(int argc, char **argv){
    if (argc < 4){
        printf("Usage: %s <values...> <position of insertion>\n", argv[0]);
        return 01;
    }
    int32 val;
    Node *head = NULL;
    char i;
    for (i = 1; i < argc-1; ++i){
        val = _m_atoi(argv[i]);
        add_node(&head, val);
    }
    print_list(head);
    insert_node(&head, _m_atoi(argv[argc-2]), _m_atoi(argv[argc-1]));
    free_nodes(&head);
    return 0;
}
