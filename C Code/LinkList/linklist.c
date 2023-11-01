#include<stdio.h>
#include<stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
void print_list(struct ListNode * head){
    struct ListNode * current = head ;
    while(current !=NULL){
        printf("%d \n",current->val);
        current = current->next;
    }

}


int main(void){
    printf("HEELT1\n");
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    
    newNode->val = 1;
    newNode->next = malloc(sizeof(struct ListNode));
    newNode->next->val = 2;
    newNode->next->next =malloc(sizeof(struct ListNode));
    newNode->next->next->val = 3;
    newNode->next->next->next =NULL;

    print_list(newNode);

    printf("ENDEND\n");
    system("pause");
    return 0;
}