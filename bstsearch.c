#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* lchild;
    struct node* rchild;
} node;

node* create_node(int val) {
    node* n = (node*)malloc(sizeof(node));
    n->value = val;
    n->lchild = NULL;
    n->rchild = NULL;
    return n;
}

node* insert_node_recurse(node* p, int x) {
    if (p == NULL) {
        p = create_node(x);
    } else if (x < p->value) {
        p->lchild = insert_node_recurse(p->lchild, x);
    } else if (x > p->value) {
        p->rchild = insert_node_recurse(p->rchild, x);
    }
    return p;
}

void search(int key, node *r)
{
    if(r==NULL)
    {
        printf("NOT FOUND");
        return;
    }
    if(r->value>key)
    {
        search(key, r->lchild);
        return;
    }
    else if(r->value<key)
    {
        search(key, r->rchild);
        return;
    }
    else
    {
        printf("FOUND");
        return;
    }
}

int main() {
    node* r = NULL;
    int x,key;
    scanf("%d", &key);
    scanf("%d", &x);
    while (x != -1) {
        r = insert_node_recurse(r, x);
        scanf("%d", &x);
    }
    search(key,r);
    return 0;
}