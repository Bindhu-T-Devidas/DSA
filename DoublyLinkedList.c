#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
int value;
struct node *next;
struct node *prev;
};
typedef struct node node;

struct list{
node *head;
node *tail;
int size;
};
typedef struct list list;

list* create_list(){
list *l = (list *)malloc( sizeof(list) );
l->head = NULL;
l->tail = NULL;
l->size = 0;
return l;
}
bool is_empty(list *list){
return (*list).size == 0;
}

void push_front_list(list *l, int value){
printf("push %d to the front\n", value);
node *n = (node*) malloc( sizeof(node) );
n->value = value;
n->prev = NULL;
n->next = l->head;
if ( is_empty(l) ) {
l->tail = n;
} else {
l->head->prev = n;
}
l->head = n;
l->size++;
return;
}


void push_back_list(list *l, int value){
printf("push %d to the back\n", value);
node *n = (node*) malloc( sizeof(node) );
n->value = value;
n->next = NULL;
n->prev = l->tail;
if (is_empty(l)) {
l->head = n;
l->tail = n;
} else {
l->tail->next = n;
l->tail = n;
}
l->size++;
}


int del_front_list(list *l){
if ( is_empty(l) ) {
printf("Error: list is empty!\n");
return 0;
}

int val = l->head->value;
node *n = l->head;
if (l->size == 1) {
l->head = NULL;
l->tail = NULL;
} else {
l->head = l->head->next;
l->head->prev = NULL;
}
l->size--;
free(n);
printf("popping value %d\n", val);
return val;
}


int del_back_list(list *l){
if ( is_empty(l) ) {
printf("Error: list is empty!\n");
return 0;
}
node *n = l->tail;
int val = n->value; //head is the same as tail
if (l->size == 1) {
l->head = NULL;
l->tail = NULL;
} else {
l->tail = n->prev;
l->tail->next = NULL;
}
free(n);
l->size--;
printf("popping value %d\n", val);
return val;
}


void display_from_front(list *l) {
printf("list from the front:\n");
if ( is_empty(l) ) {
printf("List is empty\n");
return;
}
node *n = l->head;
printf("\t %d\t", n->value);
while (n != NULL && n->next != NULL) {
n = n->next;
printf("%d\t", n->value);
}
printf("\n");
}


void display_from_back(list *l) {
printf("list from the back:\n");
if ( is_empty(l) ) {
printf("List is empty\n");
return;
}
node *n = l->tail;
printf("\t %d\t", n->value);
while (n != NULL && n->prev != NULL) {
n = n->prev;
printf("%d\t", n->value);
}
printf("\n");
}


int main(void){
list *l = create_list();
printf("size of list = %d\n", l->size);
push_front_list(l, 10);
printf("size of list = %d\n", l->size);
push_front_list(l, 20);
printf("size of list = %d\n", l->size);
display_from_front(l);
display_from_back(l);
push_back_list(l, 30);
printf("size of list = %d\n", l->size);
push_back_list(l, 40);
printf("size of list = %d\n", l->size);
display_from_front(l);
display_from_back(l);
del_front_list(l);
printf("size of list = %d\n", l->size);
display_from_front(l);
display_from_back(l);
del_back_list(l);
printf("size of list = %d\n", l->size);
display_from_front(l);
display_from_back(l);
return 0;
}