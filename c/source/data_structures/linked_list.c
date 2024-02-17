#include "linked_list.h"

// many optimizations and variations could be implemented
//  * track number of nodes 
//  * track last node 
//  * double sided linked list (size of node will go from 12 to 20 bytes)
//      but time complexity will be O(1) instead of O(n) for removal/insertion at end
//  * insert at the end of the list





void possibilities(node **head);
void insert_node(node **head, int position);
void remove_node(node **head, int position);


//#################################
int main(int argc, char **argv){
    if (argc != 2){
        printf("Correct usage: %s <size_of_linkedlist>\n", argv[0]);
        return -1;
    }

    node *head = (node*)malloc(sizeof(node)); // head of the linked list. should be 12 bytes 
    
    fill_linkedlist(&head, atoi(argv[1]));
    
    possibilities(&head);
    
    freeall(&head);
    
    return 0;
}
//####################################


void possibilities(node **head){
    while (1){
        printf("Enter 0 to exit\n");
        printf("Enter 1 to insert a node\n");
        printf("Enter 2 to remove a node\n");
        printf("Enter 3 to print the linkedlist\n");
        int choice, position;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return;
        case 1:
            printf("Position of insertion(starts at 0): ");
            scanf("%d", &position);
            insert_node(head, position);
            break;
        case 2:
            printf("Position of removal(starts at 0): ");
            scanf("%d", &position);
            remove_node(head, position);
            break;
        case 3:
            print_linkedlist(head);
            break;
        default:
            printf("Invalid choice: %d\n", choice);
        }
    }
}


void insert_node(node **head, int position){
    srand((unsigned int)time(NULL));
    struct node *temp = *head, *node_in = (node*)malloc(sizeof(node));
    node_in->value = rand() % RANGE + MIN;

    int i = 0;
    bool test = false;
    if (position == 0){
        node_in->link = *head;
        *head = node_in;
        system("clear");
        printf("node was inserted at: %d\n", position);
        return;
    }
    while (temp != NULL){
        if (i == position)
        {
            node_in->link = temp;
            test = true;
        }
        temp = temp->link;
    }
    (test == true) ? printf("node at %d was removed\n", position) : printf("%d is an invalid position\n", position);
}


void remove_node(node **head, int position){
    node *temp = (*head)->link, *prev = *head;
    bool test = false;
    if (position == 0){
        *head = (*head)->link;
        free(prev);
        system("clear");
        printf("node at %d was removed\n", position);
        return;
    }
    int i = 1;
    while (temp != NULL){
        if (i == position){
            prev->link = temp->link;
            free(temp);
            test = true;
            break;
        }
        prev = temp;
        temp = temp->link;
        i++;
    }
    system("clear");
    (test == true) ? printf("node at %d was removed\n", position) : printf("%d is an invalid position\n", position);
}