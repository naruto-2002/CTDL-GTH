#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> adj[1005];
bool visited[1005];
bool check;

void inp(){
    for(int i = 0; i <= 1005; i++) adj[i].clear();
    memset(visited, false, sizeof(visited));
    check = false;
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u, int cnt){
    if(cnt == d) check = true;
    if(check) return;
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v, cnt + 1);
    }
    visited[u] = false;
}

void slove(){
    inp();
    for(int i = 1; i <= d; i++){
        dfs(i, 1);
        if(check) break;
    }
    if(check) cout << 1;
    else cout << 0;
    cout << '\n';
}

main(){
    int t; cin >> t;
    while(t--) slove();
}


