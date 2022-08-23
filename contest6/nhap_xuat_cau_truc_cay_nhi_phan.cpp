#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *pLeft;
    struct node *pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t){
    t = NULL;
}

void ThemNodeVaoCay(TREE &t, int x){
    if(t = NULL){
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }else{
        if(t->data > x){
            ThemNodeVaoCay(t->pLeft, x);
        }
    }
}

main(){
    
}