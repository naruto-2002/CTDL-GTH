#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int> > dsc;

void inp(){
    for(int i = 0; i <= 1005; i++) adj[i].clear();
    dsc.clear();
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dsc.push_back({x, y});
    }
}

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

void dfss(int u, int s, int t){
    visited[u] = true;
    for(int v : adj[u]){
        if((u == s && v == t ) ||( u == t && v == s)) continue;
        if(!visited[v]) dfss(v, s, t);
    }
}

void canhcau(){
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= d; i++){
        if(!visited[i]){
            ++tplt;
            dfs(i);
        }
    }
    for(auto it : dsc){
        memset(visited, false, sizeof(visited));
        int x = it.first, y = it.second;
        int dem = 0;
        for(int i = 1; i <= d; i++){
            if(!visited[i]){
                ++dem;
                dfss(i, x, y);
            }
        }
        if(dem > tplt){
            cout << x << ' ' << y << ' ';
        }
    }

}

main(){
    int t; cin >> t;
    while(t--){
        inp();
        canhcau();
        cout << endl;
    }
}

