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

void check_path(int s, int t){
    memset(visited, false, sizeof(visited));
    dfs(s);
    if(visited[t]) cout << "YES";
    else cout << "NO";
}


main(){
    int t; cin >> t;
    while(t--){
        inp();
        int tt; cin >> tt;
        while(tt--){
            int a, b; cin >> a >> b;
            check_path(a, b);
            cout << '\n';
        }
    }
}