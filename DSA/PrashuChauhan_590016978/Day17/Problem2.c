// detecting the cycle in the list.



#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode{
    int val;
    struct ListNode *next;
};


bool has_cycle(struct ListNode *head){
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    if(head == NULL || head->next == NULL) return false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}