#include <stdio.h>
#include <stdlib.h>
            
            // Program to insert the fast inverse square root in the linked list
//####################################

// link node
typedef struct Node{
    float val;
    struct Node *link;
}Node;

// add node in linked list
void add_node(Node **head, float val){
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

float q_rsqrt(float number)
{
  long i;
  float x2, y;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;                       // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
  y  = * ( float * ) &i;
  y  = y * ( 1.5F - ( x2 * y * y ) );
  y  = y * ( 1.5F - ( x2 * y * y ) );
  return y;
}

void inv_all(Node **head){
    Node *temp = *head;
    while (temp != NULL){
        temp->val = q_rsqrt(temp->val);
        temp = temp->link;
    }
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

float _m_atoi(char *arr){
    char i;
    float val = 00, coeff = 01;
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
    if (argc == 1){
        printf("Usage: %s <values...> <position of insertion>\n", argv[0]);
        return 01;
    }
    float val;
    Node *head = NULL;
    char i;
    for (i = 1; i < argc; ++i){
        val = _m_atoi(argv[i]);
        add_node(&head, val);
    }
    printf("----------------Before----------------\n");
    print_list(head);

    inv_all(&head);
    
    printf("----------------After----------------\n");
    print_list(head);
    
    free_nodes(&head);
    return 0;
}