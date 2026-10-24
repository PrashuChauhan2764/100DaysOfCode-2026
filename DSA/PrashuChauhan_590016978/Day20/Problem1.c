//Problem1: remove duplicate elements from the singly linkedlist

struct node *remove_elements(struct node *start, int val){
    struct node *ptr = start;
    struct node *temp = NULL;
    if(start == NULL) return start;


    while(start != NULL && start->data == val){
        start = start->next;
    }
    ptr = start;
    while(ptr != NULL && ptr->next != NULL){
        if(ptr->next->data == val){
            ptr->next = ptr->next->next;
        }else{
            ptr = ptr->next;
        }
    }
    return start;
}