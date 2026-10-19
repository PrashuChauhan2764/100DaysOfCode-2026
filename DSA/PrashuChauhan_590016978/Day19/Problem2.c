//finding the middle node for both odd and even length of lists
//approach used: slow/fast pointer

struct node *middle_node(struct node *start){
    struct node *slow = start;
    struct node *fast = start;

    if(start == NULL || start->next == NULL) return start;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}