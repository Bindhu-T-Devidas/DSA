#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int element;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;

}node;

typedef struct list {
    int size;
    node *head;
    node *tail;
}list;

list* createlist(){
    list *lst= (list *)malloc(sizeof(list));
    lst->head=NULL;
    lst->tail=NULL;
    lst->size=0;
    printf(" \n Linked list is created ");
    return lst;
}

bool is_empty(list *lst){
    return lst->size==0 ;
}
void addfront(list *lst, int element){
   printf("\n %d will be added to the front");
   node *temp=(node *)malloc(sizeof(node));
   temp->data=element;
   temp->prev=NULL;
   temp->next=lst->head;
   if(is_empty(lst)){
    lst->tail=temp;
   }
   else{
    lst->head->prev=temp;
   }
   lst->head=temp;
   lst->size++;

}

void addBack(list *lst, int element){
    printf("\n %d will be added to the front");
    node *temp= (node *)malloc(sizeof(node));
    temp->next=NULL;
    temp->data=element;
    temp->prev=lst->tail;
    if(is_empty(lst)){
        lst->tail=temp;
        lst->head=temp;
    }
    else{
        lst->tail->next=temp;
        lst->tail=temp;
    }
    lst->size++;
    
}

int deletefront(list *lst)
{
    if(is_empty(lst)){
        printf("List is empty");
        return -1;
    }
    else{
        int del=lst->head->data;
        node *delfront=lst->head;
        if(lst->size==1){
            lst->head=NULL;
            lst->tail=NULL;
        }
        else{
            lst->head->prev=NULL;
            lst->head=lst->head->next;
            lst->size--;
            printf("popping value is %d", del);
            free(delfront);
            return del;
        }
    }
  
}
    
int deleteback(list *lst){
    if(is_empty(lst)){
        printf("List is empty");
        return -1;
    }
    else{
        node *delfront=lst->tail;
        int del=lst->tail->data;
        if(lst->size==1){
            lst->head=NULL;
            lst->tail=NULL;
        }
        else{
            lst->tail=delfront->prev;
            lst->tail->next=NULL;
        }
        free(delfront);
        lst->size--;
        
        printf("\n %d has been popped out", del);
    }

}
void traverse(list *lst)
{
    if(lst->head == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        struct node *curr;
        curr = lst->head;
        while(curr != NULL)
        {
            printf("\n%d", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main(){
    list *lst=createlist();
    addfront(lst, 5);
    addfront(lst, 9);
    addfront(lst, 11);
    addBack(lst, 23);
    
    int del1=deletefront(lst);
    int del2=deleteback(lst);
    traverse(lst);
    

    

}



