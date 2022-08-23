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

void checktltm(){
    int tplt = 0;
    for(int i = 1; i <= d; i++){
        memset(visited, false, sizeof(visited));
        for(int j : ke[i]){
            dfs(j);
            if(!visited[i]){
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

main(){
    int t; cin >> t;
    while(t--){
        input();
        checktltm();
        cout << endl;
    }
}