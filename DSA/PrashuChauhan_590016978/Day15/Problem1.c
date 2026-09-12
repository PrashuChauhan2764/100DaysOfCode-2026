// creating n linkedlist  by taking each node as input with the help of function

#include<stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node *next;
};

//FUNCTION DECLARATION
struct node *create_linkedlist(int *count);
void display_linkedlist(struct node *start);
struct node *merging_sortedLinkedlists(struct node *start1, struct node *start2, int sz);


int main(){
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    int count1 = 0,count2 = 0, totalNodes = 0;

    printf("\ncreate the likedlist in sorted order:-");
    head1 = create_linkedlist(&count1);
    printf("\nThe first linkedlist is:- \n");
    display_linkedlist(head1);
    //printf("\nThe total NOdes in linkedlist1 is: %d\n",count1);

    printf("\n\nThe second linkedlist is:- \n");
    head2 = create_linkedlist(&count2);
    display_linkedlist(head2);

    totalNodes = count1 + count2;
    printf("\nThe total no. NOdes in ll1 + ll2 is: %d\n",totalNodes);

    head3 = merging_sortedLinkedlists(head1, head2, totalNodes);
    printf("\nThe Merger sorted linkedlist is:- \n");
    display_linkedlist(head3);

    return 0;
}




//FUNCTION DEFINITION
struct node *create_linkedlist(int *count){
    struct node *newnode, *ptr, *start = NULL;
    int val;

    printf("\nEnter -1 to stop");
    printf("\nEnter value: ");
    scanf("%d",&val);

    while(val != -1){
        newnode = (struct node *)malloc(sizeof(struct node));
        (*count)++;
        newnode->data = val;
        newnode->next = NULL;
        
        if(start == NULL){
            start = newnode;
            ptr = start;
        }
        else{
            ptr->next = newnode;
            ptr = newnode;
        }
        printf("\nEnter value: ");
        scanf("%d",&val);
    }
    return start;
}

void display_linkedlist(struct node *start){
    struct node *ptr;
    if(start != NULL){

        ptr = start;
        do{
         printf("%d",ptr->data);
         ptr = ptr->next;
         if(ptr != NULL){
            printf(" -> ");
         }
        }while(ptr != NULL);
    }else{
        printf("\nThe linkedlist is empty!!");
    }
}


struct node *merging_sortedLinkedlists(struct node *start1, struct node *start2, int sz){
    struct node *start3 = NULL, *ptr3;
    struct node *ptr1 = start1;
    struct node *ptr2 = start2;
    int small = 0, i;

    for(i=0; i<sz; i++){
        
        if(ptr1 != NULL){

            small = ptr1->data;
            printf("\nsmall = %d",small);
            if(ptr2 != NULL && ptr2->data <= small){
                small = ptr2->data;
                ptr2 = ptr2->next;
                printf("\nsmall of ll2 = %d",small);
            }else{
                ptr1 = ptr1->next;
            }

        }else{
            small = ptr2->data;
            if(ptr2 != NULL){
    
                ptr2 = ptr2->next;
            }
        }

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        if(start3 == NULL){

            start3 = newnode;
            ptr3 = start3;
        }else{
            ptr3->next = newnode;
            ptr3 = ptr3->next;
        }
        printf("\nnewnode data is: %d",newnode->data);
        newnode->data = small;
    }
    return start3;
}

