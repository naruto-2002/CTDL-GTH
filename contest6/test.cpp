#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int Data;
    struct Node *Next;
}Node;
typedef struct{
    Node *top;
} Stack;
void KhoiTaoStack(Stack *s){
    s->top = NULL;
}
Node *KhoiTaoNode(int *x){
    Node *p = new Node();
    p->Next = NULL;
    p->Data = *x;
    return p;
}

bool IsEmpty(Stack *s)
{
    if(s->top == NULL) return true;
    else return false;
}

void push(Stack *s, Node *p){
    if(s->top == NULL)
    {
        s->top = p;
    }
    else{
        p->Next = s->top->Data;
        s->top = p;
    }
}

int Pop(Stack *s)
{
    if(IsEmpty(s)== false)
    {
        Node *p = s->top;
        int x = p->Data;
        s->top->Data = s->top->Next;
        delete p;
        return x;
    }
}

void chuyendoi(int n, Stack *s)
{
    while(n!=0)
    {
        int r = n % 2;
        Node *p = KhoiTaoNode(&r);
        push(s,p);
        n=n/2;
    }
}

void XuatStack(Stack *s)
{
    while(IsEmpty(s)== false)
    {
        int x = Pop(s);
        cout << x;
    }
}
main()
{
    Stack *s;
    KhoiTaoStack(s);
    int n;
    cin >> n;
    chuyendoi(n, s);
    XuatStack(s);
}