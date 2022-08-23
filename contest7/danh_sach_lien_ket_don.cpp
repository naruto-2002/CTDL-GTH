#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *pNext;
};

typedef struct node NODE;

struct listt{
    NODE *pHead;
    NODE *pTail;
};

typedef struct listt LIST;

void init(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE *initnode(int x){
    NODE *p = new NODE;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void addfirst(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addend(LIST &l, NODE *p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void output(LIST l){
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        cout << k->data << ' ';
    }
}

main(){
    LIST l;
    init(l);
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        NODE *p = initnode(x);
        addend(l, p);
    }
    output(l);


}