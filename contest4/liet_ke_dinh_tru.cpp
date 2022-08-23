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

void bfs(int u){
    queue<int> q;
    q.push(u);
    while(q.size() > 0){
        int v = q.front(); q.pop();
        for(auto x : adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void lkdtr(){
    memset(visited, false, sizeof(visited));
    int tplt = 0;
    for(int i = 1; i <= d; i++){
        if(!visited[i]){
            ++tplt;
            bfs(i);
        }
    }
    for(int i = 1; i <= d; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int dem = 0;
        for(int j = 1; j <= d; j++){
            if(!visited[j]){
                ++dem;
                bfs(j);
            }
        }
        if(dem > tplt) cout << i << ' ';
    }
    cout << endl;
}

main(){
    int t; cin >> t;
    while(t--){
        inp();
        lkdtr();
    }
}