#include<bits/stdc++.h>
using namespace std;
int n, m, ma;
vector<pair<int, int>> ke;
bool visited[1005];

void input(){
    ke.clear();
    memset(visited, false, sizeof(visited));
    cin >> n >> m;
    ma = max(n, m);
    char c;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c;
            if(c == 'W'){
                ke.push_back({i, j});
            }
        }
    }
}


void dfs(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(q.size()){
        int v = q.front(); q.pop();
        for(int x : ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void cntstplt(){
    int tplt = 0;
    for(int i = 1; i <= ma; i++){
        if(!visited[i]){
            ++tplt;
            bfs(i);
        }
    }
    cout << tplt << endl;
}

main(){
    input();
    cntstplt();
}