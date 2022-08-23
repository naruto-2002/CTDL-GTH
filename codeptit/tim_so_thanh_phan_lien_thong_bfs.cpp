#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> ke[1005];
bool visited[1005];

void input(){
    for(int i = 0; i <= 1005; i++) ke[i].clear();
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
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

void cnttplt(){
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= d; i++){
        if(!visited[i]){
            ++tplt;
        }
    }
    cout << tplt;
}


main(){
    int t; cin >> t;
    while(t--){
        input();
        cnttplt();
    }
}