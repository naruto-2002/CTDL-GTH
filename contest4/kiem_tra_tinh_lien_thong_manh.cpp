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
    }
}

int dem;
void dfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(q.size() > 0){
        int v = q.front(); q.pop();
        dem++;
        for(auto x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

string check(){
    for(int i = 1; i <= d; i++){
        memset(visited, false, sizeof(visited));
        dem = 0;
        if(!visited[i]){
            dfs(i);
            if(dem != d) return "NO";
        }
    }
    return "YES";
}

main(){
    int t; cin >> t;
    while(t--){
        inp();
        cout << check() << '\n';
    }
}