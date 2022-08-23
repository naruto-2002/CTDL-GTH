#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10005];
bool visited[10005];
bool check;
string res;


void inp(){
    for(int i = 0; i <= 10005; i++) adj[i].clear();
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    while(m--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
}

void dfs(int u, int par, string s){
    if(check) return;
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v, u, s + " " + to_string(v));
        }else if(v != par && v == 1){
            check = true, res = s;
        }
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        inp();
        check = false;
        dfs(1, 0, "1");
        if(check){
            cout << res << " 1";
        }else cout << "NO";
        cout << endl;
    }
}
