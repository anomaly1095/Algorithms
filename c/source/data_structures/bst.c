#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 9999
#define MIN -9999
#define RANGE (MAX - MIN + 1)

typedef struct node{
    int value;
    struct node *right;
    struct node *left;
}bst_node;


bst_node *new_node(int value){
    bst_node *_new = (bst_node*)malloc(sizeof(bst_node));
    _new->left = NULL;
    _new->right = NULL;
    _new->value = value;
    return _new;
}

void insert_value(bst_node **head, int value){
    bst_node *temp = *head;
    if (value >= temp->value){ // go right if value >=
        if (temp->right == NULL){
            temp->right = new_node(value);
            return;
        }
        insert_value(&(temp->right), value);
    }else{ // go left if value < 
        if (temp->left == NULL){
            temp->left = new_node(value);
            return;
        }
        insert_value(&(temp->left), value);
    }
}


void fill_tree(bst_node **head, int size){
    srand((unsigned int)time(NULL));
    int value;
    bst_node* temp = *head;
    
    for (int i = 0; i < size; i++){
        value = rand() % RANGE + MIN;
        insert_value(head, value);
    }
}



void print_tree(bst_node **head, int _tab){
    bst_node *temp = *head;
    if (temp != NULL){
        for (int i = 0; i < _tab; i++){
            printf("\t");
        }
        printf("%d\n", temp->value);
        print_tree(&(temp->right), _tab+1);
        print_tree(&(temp->left), _tab-1);
    }
    return;
}


int main(int argc, char **argv){
    if (argc != 2){
        printf("Usage: %s <node numbers>\n", argv[0]);
        return 1;
    }
    
    bst_node* head = (bst_node*)malloc(sizeof(bst_node));
    head->left = NULL; head->right = NULL; head->value = 0;
    
    fill_tree(&head, atoi(argv[1]));
    print_tree(&head, 10);
    
    return 0;
}
