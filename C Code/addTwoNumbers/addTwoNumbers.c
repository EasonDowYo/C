#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *result = NULL;
    struct ListNode **p = &result;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry > 0){
        int sum = carry;
        if (l1 != NULL){
            sum = sum + l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL){
            sum = sum + l2->val;
            l2 = l2->next;
        }
        *p = malloc(sizeof(struct ListNode));
        (*p)->val = sum % 10;
        (*p)->next = NULL;
        p = &((*p)->next);
        carry = sum / 10;
    }
    return result;
}


int main(void) {
    printf("Hello! World!GGG\n");




    return 0;
}


