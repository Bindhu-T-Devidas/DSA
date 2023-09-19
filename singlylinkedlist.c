#include<stdio.h>
#include<stdlib.h>

int element, choice;

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct list
{
    node *head;
    int size;
}list;

list* createlist()
{
    list *lst = (list *)malloc(sizeof(list));
    (*lst).head = NULL; //can also be written as lst->head = NULL
    lst->size = 0; //can also be written as (*lst).size = 0
    //By saying lst-> or (*lst), it dereferences it from the struct. This is necessary because lst is a pointer.
    printf("\nLinked list created \n");
    return lst;
}

void traverse(list *lst)
{
    if(lst->head == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        node *curr;
        curr = lst->head;
        while(curr != NULL)
        {
            printf("\n%d", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

void addFront(list *lst, int element)
{
    if(lst->head == NULL)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = element;
        temp->next = NULL;
        lst->head = temp;
        lst->size++;
        printf("\n%d has been inserted into the front\n", (lst->head)->data);
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = element;
        temp->next = lst->head;
        lst->head = temp;
        lst->size++;
        printf("\n%d has been inserted into the front\n", (lst->head)->data);
    }
}

void addBack(list *lst, int element)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = element;
    temp -> next = NULL;
    
    if(lst->head == NULL)
    {
        lst->head = temp;
    }

    struct node *curr;
    curr = lst->head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    if(curr->next == NULL)
    {
        curr->next = temp;
    }
    lst->size++;
    printf("\n%d has been inserted into the back\n", (curr->next)->data);
}

void insertAfter(list *lst, int element, int key)
{
    node *n, *p;
    int insertCheck = 0;
    p = lst->head;
    if(p == NULL)
    {
        printf("\nList is empty.. %d not in list\n", key);
        insertCheck = 1;
    }
    while(p != NULL)
    {
        if(p->data == key) 
        {
            n = (node *)malloc(sizeof(node));
            n->data = element;
            n->next = p->next;
            p->next = n;
            lst->size++;
            printf("\n%d has been inserted after %d\n", element, key);
            insertCheck = 1;
        }
        p = p->next;       
    }
    if(insertCheck == 0)
    {
        printf("\n%d not found in list\n");
    } 
}

void insertBefore(list *lst, int element, int key)
{
    node *n, *q;
    int insertCheck = 0;
    q = lst->head;
    if(q == NULL)
    {
        printf("\nList is empty.. %d not in list\n", key);
        insertCheck = 1;
    }

    if(key == q->data)
    {
        n = (node *)malloc(sizeof(node));
        n->data = element;
        n->next = q;
        n = lst->head;
        lst->size++;
        printf("\n%d has been inserted before %d", element, key);
        insertCheck = 1;
    }

    while(q->next != NULL)
    {
        if((q->next)->data == key)
        {
            n = (node *)malloc(sizeof(node));
            n->data = element;
            n->next = q->next;
            q->next = n;
            lst->size++;
            printf("\n%d has been inserted before %d\n", element, key);
            insertCheck = 1;
        }
        q = q->next;
    }
    if(insertCheck == 0)
    {
        printf("\n%d not found in list\n");
    } 
}

int deleteFront(list *lst)
{
    if(lst->head == NULL)
    {
        printf("\nLinked list is empty.. Please insert items to continue!\n");
        return -1; //what if element is -1?
    } 
    else
    {
        int delDataFront;
        node *delFront;
        delFront = lst->head;
        delDataFront = (lst->head)->data;
        lst->head = (lst->head)->next;
        lst->size--;
        printf("\n%d has been deleted from the front\n", delDataFront);
        free(delFront);
        return delDataFront;
    }
}

int deleteBack(list *lst)
{
    if(lst->head == NULL)
    {
        printf("\nLinked list is empty.. Please insert items to continue!\n");
        return -1; //what if element is -1?
    } 
    else if((lst->head)->next == NULL)
    {
        int delDataBack;
        node *delBack;
        delBack = lst->head;
        delDataBack = (lst->head)->data;
        lst->head = NULL;
        lst->size --;
        printf("\n%d is deleted from the back\n", delDataBack);
        free(delBack);
        return delDataBack;
    }
    else
    {
        int delDataBack;
        node *delBack;
        node *curr;
        curr = lst->head;
        while((curr->next)->next != NULL)
        {
            curr = curr->next;
        }
        if((curr->next)->next == NULL)
        {
            delDataBack = (curr->next)->data;
            delBack = curr->next;
            curr->next = NULL;
            lst->size --;
            printf("\n%d is deleted from the back\n", delDataBack);
            free(delBack);
            return delDataBack;
        }
    }
}

int main()
{
    list *lst = createlist();
    for(;;)
    {
        int ele, key, ch;
        printf("\nMENU OF SINGLE LINKED LIST\n");
        printf("\n1.Display list");
        printf("\n2.Add to front of list");
        printf("\n3.Add to back of list");
        printf("\n4.Add after an element");
        printf("\n5.Add before an element");
        printf("\n6.Delete from front of list");
        printf("\n7.Delete from back of list");
        printf("\n8.Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);
int delDataFront;
int delDataBack ;
        switch(ch)
        {
            case 1:
                traverse(lst);
                break;
            case 2:
                printf("\nEnter element to be inserted to the front: ");
                scanf("%d", &ele);
                addFront(lst, ele);
                break;
            case 3:
                printf("\nEnter element to be inserted to the back: ");
                scanf("%d", &ele);
                addBack(lst, ele);
                break;
            case 4: 
                printf("\nEnter key of element to insert after: ");
                scanf("%d", &key);
                printf("\nEnter element to be inserted after an element: ");
                scanf("%d", &ele);
                insertAfter(lst, ele, key);
                break;
            case 5: 
                printf("\nEnter key of element to insert before: ");
                scanf("%d", &key);
                printf("\nEnter element to be inserted before an element: ");
                scanf("%d", &ele);
                insertBefore(lst, ele, key);
                break;
            case 6:
                delDataFront = deleteFront(lst);
                break;
            case 7:
                delDataBack = deleteBack(lst);
                break; 
            case 8:
                exit(0); 
        }  
    }
    return 0;
}