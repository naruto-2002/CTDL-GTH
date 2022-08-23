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
    if(T == NULL) T= new node(x);
    else{
        if(x < T->data) add_node(T->pLeft, x);
        else add_node(T->pRight, x);
    }
}

void browse(Tree T){
    if(T == NULL) return;
     cout << T->data << ' ';
    if(T->pLeft != NULL) browse(T->pLeft);
    if(T->pRight != NULL) browse(T->pRight);
}

main(){
    int t; cin >> t;
    while(t--){
        Tree T= NULL;
        int n; cin >> n;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            add_node(T, x);
        }
        browse(T);
        cout << '\n';
    }

}