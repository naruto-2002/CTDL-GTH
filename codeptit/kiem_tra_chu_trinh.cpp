#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> ke[1005];
bool visited[1005];

void input(){
    for(int i = 0; i <= 1005; i++) ke[i].clear();
    memset(visited, false, sizeof(visited));
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

bool dfs(int u, int par){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            if(dfs(v, u)) return true;
        }else if(v != par) return true;
    }
    return false;
}

main(){
    int t; cin >> t;
    while(t--){
        input();
        int ok = 1;
        for(int i = 1; i <= d; i++){
            if(!visited[i]){
                if(dfs(i,0)){
                    ok = 0;
                    cout << "YES\n";
                    break;
                }
            }
        }
        if(ok) cout << "NO\n";
    }

}