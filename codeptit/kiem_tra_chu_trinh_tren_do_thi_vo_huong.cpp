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

bool check(int u, int par){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            if(check(v, u)) return true;
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
                if(check(i, 0)){
                    cout << "YES\n";
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) cout << "NO\n";
    }
}