//palindrome code

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    //finding middle node
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse second half
    struct ListNode *prev = NULL;
    struct ListNode *nextptr = NULL;

    while(slow != NULL){
        nextptr = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextptr;
    }

    while(prev != NULL){
        if(head->val != prev->val) return false;
        head = head->next;
        prev = prev->next;
    }
    return true;
    
}