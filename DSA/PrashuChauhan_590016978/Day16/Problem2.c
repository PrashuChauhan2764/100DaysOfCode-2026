//this code  is used to delete the node at the last of the doubly linkedlist in existing linkedlist.

#include<stdlib.h>
#include<stdio.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

//FUNCTION DECLARATION
struct node *create_doublyLinkedlist(struct node *start);
void display_linkedlist(struct node *start);
void display_reversed_linkedlist(struct node *start);
struct node *delete_at_End(struct node *start);


int main(){
    
    struct node *start = NULL;
    start = create_doublyLinkedlist(start);
    printf("\nThe Doubly linkedlist BEFORE DELETION is: \n");
    display_linkedlist(start);

    printf("\nLinkedList in reverse order before deletion:- \n");
    display_reversed_linkedlist(start);

    start = delete_at_End(start);

    printf("\nAfter Deletion new node:- \n");
    display_linkedlist(start);


    printf("\nLinkedList in reverse order after deletion:- \n");
    display_reversed_linkedlist(start);


    return 0;
}




//FUNCTION DEFINITION
struct node *create_doublyLinkedlist(struct node* start){
    struct node *newnode, *ptr;
    int val;

    printf("\nEnter -1 to stop");
    printf("\nEnter value: ");
    scanf("%d",&val);

    while(val != -1){
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->prev = NULL;
        newnode->data = val;
        newnode->next = NULL;
        
        if(start == NULL){
            start = newnode;
            ptr = start;
        }
        else{
            ptr->next = newnode;
            newnode->prev = ptr;
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


void display_reversed_linkedlist(struct node *start){
    struct node *revptr = NULL;

    revptr = start;
    while(revptr->next != NULL){
        revptr = revptr->next;
    }
    start = revptr;

    struct node *ptr;
    if(start != NULL){

        ptr = start;
        do{
         printf("%d",ptr->data);
         ptr = ptr->prev;
         if(ptr != NULL){
            printf(" -> ");
         }
        }while(ptr != NULL);
    }else{
        printf("\nThe linkedlist is empty!!");
    }
    
}


//function to delete first node 
struct node *delete_at_End(struct node *start){
    struct node *ptr = start;
    
    if(start->next == NULL){
        start = NULL;
        
    }else{

        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
    }
    return start;
}

