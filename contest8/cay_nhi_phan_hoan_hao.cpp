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

void inittree(Tree &T){
    T = NULL;
}

void add_node(Tree &T, int u, int v, char x){
    if(T == NULL){
        T = new node(u);
        Tree p = new node(v);
        if(x == 'L') T->pLeft = p;
        else T->pRight = p; 
    }else{
        if(T->data == u){
            Tree p = new node(v);
            if(x == 'L') T->pLeft = p;
            else T->pRight = p;
        }else{
            if(T->pLeft != NULL) add_node(T->pLeft, u, v, x);
            if(T->pRight != NULL) add_node(T->pRight, u, v, x);
        }
    }
}

bool check = true;
void slove1(Tree T){
    if(T->pLeft == NULL && T->pRight != NULL) check = false;
    else if(T->pLeft != NULL && T->pRight == NULL) check = false;
    else{
        if(T->pLeft != NULL) slove1(T->pLeft);
        if(T->pRight != NULL) slove1(T->pRight);
    }
}

set<int> X;
void slove2(Tree T, int cnt){
    if(T->pLeft == NULL && T->pRight == NULL){
        X.insert(cnt);
    }else{
        if(T->pLeft != NULL) slove2(T->pLeft, cnt + 1);
        if(T->pRight != NULL) slove2(T->pRight, cnt + 1);
    }
}

main(){
    int t; cin >> t;
    while(t--){
        X.clear();
        check = true;
        Tree T;
        inittree(T);
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            int u, v;
            char x;
            cin >> u >> v >> x;
            add_node(T, u, v, x);
        }
        slove1(T);
        slove2(T, 0);
        if(check && X.size() <= 1) cout << "Yes\n";
        else cout << "No\n";
    }

}