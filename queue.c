#include <stdio.h>
#include <stdlib.h>
#define size 4
int rear=-1;
int front=-1,ele;
int myqueue[size];
void enqueue();
int dequeue();
void display();
int main() {
    int ch;
    for(;;){
        printf("1.Enq \n");
        printf("2.deq \n");
        printf("3.Display \n");
        printf("4.Exit \n");
    printf("Enter your choice \n");
    scanf("%d", &ch);
    
    switch (ch)
    {
    case 1:
        printf("Enter the element to Enqueue \n");
        scanf("%d", &ele);
        enqueue();
        break;
    case 2:
    int x;
    x=dequeue();
    printf("element deleted is %d", x);
    break;
    
    case 3:
    display();
    break;

    case 4:
        exit();
    }
    }

void enqueue(){
    if(rear==)
}
}