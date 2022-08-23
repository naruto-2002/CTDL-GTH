#include<bits/stdc++.h>
using namespace std;

int d, u, v;
vector<int> ke[1005];
bool visited[1005];
int truoc[1005];

void init(){
    for(int i = 0; i <= 1005; i++) ke[i].clear();
    cin >> d;
    int t = d - 1;
    while(t--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

int res = 0;
void dfs(int u, int v, int cnt){
    visited[u] = true;
    if(u == v){
        res = cnt;
        return;
    }
    for(int x : ke[u]){
        if(!visited[x]){
            dfs(x, v, cnt + 1);
        }
    }
}


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        init();
        int tt; cin >> tt;
        while(tt--){
            res = 0;
            memset(visited, false, sizeof(visited));
            cin >> u >> v;
            dfs(u, v, 0);
            cout << res << endl;
        }
    }
}