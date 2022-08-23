#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* pLeft;
    Node* pRight;
    Node(int x){
        this->data = x;
        pLeft = pRight = NULL;
    }
};

typedef Node node;
typedef node* Tree;

void add_node(Tree &T, int x){
    if(T == NULL) T = new node(x);
    else{
        if(x < T->data) add_node(T->pLeft, x);
        else if(x > T->data) add_node(T->pRight, x);
    }
}

int res = 0;
void slove(Tree &T){
    if(T->pLeft != NULL && T->pRight != NULL) res += 1;
    else if(T->pLeft != NULL && T->pRight == NULL) res += 1;
    else if(T->pLeft == NULL && T->pRight != NULL) res += 1;
    if(T->pLeft != NULL) slove(T->pLeft);
    if(T->pRight != NULL) slove(T->pRight);
}

main(){
    int t; cin >> t;
    while(t--){
        res = 0;
        Tree T = NULL;
        int n; cin >> n;
        int tt = n;
        while(tt--){
            int x; cin >> x;
            add_node(T, x);
        }
        slove(T);
        cout << res << endl;
    }
}