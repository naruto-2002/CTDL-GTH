#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> ke[1005];
bool visited[1005];

void init(){
    for(int i = 0; i <= 1005; i++) ke[i].clear();
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void dfs(int u){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]) dfs(v);
    }
}

void lkdtr(){
    memset(visited, false, sizeof(visited));
    int tplt = 0;
    for(int i = 1; i <= d; i++){
        if(!visited[i]){
            ++tplt;
            dfs(i);
        }
    }
    for(int i = 1; i <= d; i++){
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        visited[i] = true;
        for(int j = 1; j <= d; j++){
            if(!visited[j]){
                ++cnt;
                dfs(j);
            }
        }
        if(cnt > tplt) cout << i << ' ';
    }

}

main(){
    int t; cin >> t;
    while(t--){
        init();
        lkdtr();
        cout << '\n';
    }
}