// creating singled linkedlist n pairing the adjacent pairs and  return the new head
#include<stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node *next;
};

//FUNCTION DECLARATION
struct node *create_linkedlist(struct node *start);
void display_linkedlist(struct node *start);
struct node *pair_adjacentNodes(struct node *start);



int main(){
    
    struct node *start = NULL,*head = NULL;
    start = create_linkedlist(start);
    printf("\nThe linkedlist Before pairing is:- \n");
    display_linkedlist(start);

    start = pair_adjacentNodes(start);
    printf("\nThe linkedlist After pairing is:- \n");
    display_linkedlist(start);
    return 0;
}




//FUNCTION DEFINITION
struct node *create_linkedlist(struct node* start){
    struct node *newnode, *ptr;
    int val;

    printf("\nEnter -1 to stop");
    printf("\nEnter value: ");
    scanf("%d",&val);

    while(val != -1){
        newnode = (struct node *)malloc(sizeof(struct node));
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


struct node *pair_adjacentNodes(struct node *head){
    struct node *prev = NULL;
    struct node *third = NULL;
    
    //base case;
    if(head == NULL || head->next == NULL) return NULL;
    else{
        struct node *first = head;
        struct node *second = head->next;

        //swaping of nodes
        while(first != NULL && second != NULL){
            third = second->next;
            second->next = first;
            first->next = third;
        
            if(prev != NULL)prev->next = second;
            else head = second;
        
            //updation of pointers
            prev = first;
            first = third;
            if(third != NULL) second = third->next;
            else second = NULL;
            
        }
    }


        

    return head;
}



