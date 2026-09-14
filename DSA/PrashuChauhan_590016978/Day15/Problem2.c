//this function reverse the given singled linkedlist


struct node *reverse_linkedlist(struct node *start){

    struct node *curr = start; //curr represent the current node
    struct node *ptr = NULL; //ptr is the next pointer
    struct node *prev = NULL; //prev repst. the previous node

    while(curr != NULL){

        printf("\nHEllo");
        ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ptr;
    }
    start = prev;
    return prev;
}