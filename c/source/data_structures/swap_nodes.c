#include "linked_list.h"


void swap_nodes_in_paires(node **head);
void swap_values_in_paires(node **head);

int main(int argc, char **argv){
    if (argc != 2)
        return -1;
    
    node *head = (node*)malloc(sizeof(node));
    fill_linkedlist(&head, atoi(argv[1]));
    return 0;
}

// by changing values
void swap_values_in_paires(node **head){
    node *temp = *head;
    int val;
    while (temp->link != NULL){
        val = temp->value;
        temp->value = temp->link->value;
        temp->link->value = val;
        temp = temp->link->link;
    }
}

// by swapping fulll node
void swap_nodes_in_paires(node **head){
    node *temp = *head;
    int val;
    while (temp->link != NULL){
        val = temp->value;
        temp->value = temp->link->value;
        temp->link->value = val;
        temp = temp->link->link;
    }
}