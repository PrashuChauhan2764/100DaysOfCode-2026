//deletion of duplicate nodes from the sorted list
//approach used: single pointer approach.

struct node *remove_duplicateNode(struct node *head){
    struct node *ptr = head;
    struct node *temp = NULL;
    if(head == NULL || head->next == NULL) return head;
    while(ptr != NULL){
        if(ptr->next != NULL && ptr->data == ptr->next->data){
            temp = ptr->next;
            ptr->next = temp->next;
        }else{
            ptr = ptr->next;
        }

        if(temp != NULL){
            free(temp);
            temp = NULL;
        }
    }

    return head;    
}
