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

void browse(Tree T){
    if(T == NULL) return;
    stack<Tree> S1, S2;
    S1.push(T);
    while(S1.size() > 0 || S2.size() > 0){
        while(S1.size() > 0){
            Tree tmp = S1.top(); S1.pop();
            cout << tmp->data << ' ';
            if(tmp->pRight != NULL) S2.push(tmp->pRight);
            if(tmp->pLeft != NULL) S2.push(tmp->pLeft);
        }
        while(S2.size() > 0){
            Tree tmp = S2.top(); S2.pop();
            cout << tmp->data << ' ';
            if(tmp->pLeft != NULL) S1.push(tmp->pLeft);
            if(tmp->pRight != NULL) S1.push(tmp->pRight);
        }
    }
}

main(){
    int t; cin >> t;
    while(t--){
        Tree T = NULL;
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            int u, v;
            char x;
            cin >> u >> v >> x;
            add_node(T, u, v, x);
        }
        browse(T);
        cout << '\n';
    }

}