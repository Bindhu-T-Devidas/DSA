#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int data;
    struct tnode *lchild;
    struct tnode *rchild;
};
typedef struct tnode tnode;

tnode *create_tree(int value)
{
    tnode *tn = (tnode *)malloc(sizeof(tnode));
    tn->data = value;
    tn->lchild = NULL;
    tn->rchild = NULL;
    return tn;
}

tnode *insert_recurse(tnode *p, int value)
{
   if(p==NULL)
    p = create_tree(value);
   else if(value < p->data)
    p->lchild = insert_recurse(p->lchild, value);
   else if(value > p->data)
    p->rchild = insert_recurse(p->rchild, value);
   else
    printf("%d is already present!\n",value);
   return p;
}
void maximum(tnode *p)
{
    if(p->rchild!=NULL)
        maximum(p->rchild);
    else
    printf("%d\n",p->data);
}

void minimum(tnode *p)
{
    if(p->lchild!=NULL)
        minimum(p->lchild);
    else
    printf("%d\n",p->data);
}

int main(){
    tnode *root = NULL;
    int input;
    scanf("%d",&input);
    while(input != -1)
    {
        root = insert_recurse(root,input);
        scanf("%d",&input);
    }
    if(root!= NULL)
    {
        minimum(root);
        maximum(root);
    }
}