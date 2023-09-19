#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int value;
    struct tnode* lchild;
    struct tnode* rchild;
} tnode;

tnode* create_node(int val) {
    tnode* newNode = (tnode*)malloc(sizeof(tnode));
    newNode->value = val;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

void preorder(tnode* tn) {
    if (tn != NULL) {
        printf("%d \n", tn->value);
        preorder(tn->lchild);
        preorder(tn->rchild);
    }
}

void inorder(tnode* tn) {
    if (tn != NULL) {
        inorder(tn->lchild);
        printf("%d \n", tn->value);
        inorder(tn->rchild);
    }
}

void postorder(tnode* tn) {
    if (tn != NULL) {
        postorder(tn->lchild);
        postorder(tn->rchild);
        printf("%d \n", tn->value);
    }
}

tnode* insert_node_recurse(tnode* p, int x) {
    if (p == NULL) {
        p = create_node(x);
    } else if (x < p->value) {
        p->lchild = insert_node_recurse(p->lchild, x);
    } else if (x > p->value) {
        p->rchild = insert_node_recurse(p->rchild, x);
    }
    return p;
}

int main() {
    tnode* root = NULL;
    int x;
    scanf("%d", &x);
    while (x != -1) {
        root = insert_node_recurse(root, x);
        scanf("%d", &x);
    }
    preorder(root);
    inorder(root);
    postorder(root);

    return 0;
}