#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val;
    struct node * next;
}node_type;

void print_list(node_type * head){
    node_type * current = head ;
    while(current !=NULL){
        printf("%d \n",current->val);
        current = current->next;
    }

}

void add_end(node_type *head,int val){
    node_type *current=head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next=malloc(sizeof(node_type));
    current->next->val = val;
    current->next->next = NULL;
}

void add_first(node_type **head,int val){
    node_type *new_node = malloc(sizeof(node_type));
    new_node->val = val;
    new_node->next = *head;

    *head = new_node;

}

void rm_list_first(node_type **head){
    node_type *new_list = malloc(sizeof(node_type));
    new_list = (*head)->next;
    free(*head);
    *head = new_list;
}


int main(){

    node_type *head = NULL;
    head = malloc(sizeof(node_type));
    if (head == NULL){
        return 1;
    }

    head->val =1;
    head->next = malloc(sizeof(node_type));
    head->next->val=2;
    head->next->next=NULL;

    print_list(head);
    
    add_end(head,3);

    print_list(head);

    add_first(&head,0);

    print_list(head);

    rm_list_first(&head);

    print_list(head);
    return 0;
}

