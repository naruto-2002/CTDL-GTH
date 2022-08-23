#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> ke[1005];
int color[1005];

void input(){
    for(int i = 0; i <= 1005; i++) ke[i].clear();
    memset(color, 0, sizeof(color));
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

bool check(int u, int par){
    color[u] = 1;
    for(int v : ke[u]){
        if(!color[v]){
            if(check(v, u)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2;
    return false;
}



main(){
    int t; cin >> t;
    while(t--){
        input();
        int ok = 1;
        for(int i = 1; i <= d; i++){
            if(!color[i]){
                if(check(i, 0)){
                    ok = 0;
                    cout << "YES\n";
                    break;
                }
            }
        }
        if(ok) cout << "NO\n";
    }
}