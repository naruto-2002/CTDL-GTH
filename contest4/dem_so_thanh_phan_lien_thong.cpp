#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> adj[1005];
bool visited[1005];

void inp(){
    for(int i = 0; i <= 1005; i++) adj[i].clear();
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

void dstplt(){
    memset(visited, false, sizeof(visited));
    int tplt = 0;
    for(int i = 1; i <= d; i++){
        if(!visited[i]){
            ++tplt;
            dfs(i);
        }
    }
    cout << tplt << endl;
}

main(){
    int t; cin >> t;
    while(t--){
        inp();
        dstplt();
    }
}