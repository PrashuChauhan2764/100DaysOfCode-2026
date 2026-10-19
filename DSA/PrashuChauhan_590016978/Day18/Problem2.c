//remove the node from the end of the linkedlist.

struct node *delete_nthNode(struct node *start,int totalNodes, int n){
    struct node *pptr = NULL;
    int index = 0;
    if(start == NULL || totalNodes == 0){
        printf("\nLinkedlist is empty!!\n");
        return start;
    }
    if(n < 1 || n > totalNodes){
        printf("\nOut of Bound value");
        return start;
    }

    index = (totalNodes - n) + 1;
    struct node *temp ;
    
    if(index == 1){
        temp = start;
        start = start->next;
    }else{
        pptr = start;
        for(int i=1; i<index-1; i++)
            pptr = pptr->next;
        
            temp = pptr->next;
            pptr->next = temp->next;
    }
    free(temp);
    printf("\nLinkedlist after deletion\n");
    return start;
}