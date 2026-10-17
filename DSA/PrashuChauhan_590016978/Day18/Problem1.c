//Rotate linked list pgm #61

struct node *shifting_by_k(struct node *start, int k){
    struct node *ptr = start;
    struct node *pptr = start;
    int n=0,idx=0;

    if(start == NULL || start->next == NULL) return start;
    n=1;
    while(ptr->next != NULL){
        n++;
        ptr = ptr->next;
    }
    printf("\nThe Length of the linkedlist is: %d",n);
    k = k % n;
    if(k == 0) return start;
    idx = n - k;
    for(int i=1; i<idx; i++)
        pptr = pptr->next;

    ptr->next = start;
    start = pptr->next;
    pptr->next = NULL;
    return start;
}