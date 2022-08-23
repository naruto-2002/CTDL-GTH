#include<bits/stdc++.h>
using namespace std;
int d, c, s, t;
vector<int> ke[1005];
bool visited[1005];
int parent[1005];

void input(){
    for(int i = 0; i <= 1005; i++) ke[i].clear();
    memset(visited, false, sizeof(visited));
    cin >> d >> c >> s >> t;
    while(c--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void dfs(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

void path(){
    dfs(s);
    if(!visited[t]){
        cout << -1;
    }else{
        vector<int> res;
        while(t != s){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for(int x : res) cout << x << ' ';
    }

}

main(){
    int t; cin >> t;
    while(t--){
        input();
        path();
        cout << endl;
    }
}