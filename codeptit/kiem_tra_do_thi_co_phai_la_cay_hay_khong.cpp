#include<bits/stdc++.h>
using namespace std;
 int d;
 vector<int> ke[1005];
 bool visited[1005];

 void input(){
     for(int i = 0; i <= 1005; i++) ke[i].clear();
     cin >> d;
     int c = d - 1;
     while(c--){
         int x, y; cin >> x >> y;
         ke[x].push_back(y);
         ke[y].push_back(x);
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

bool dfs(int u, int par){
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            if(dfs(v, u)) return true;
            else if(v != par) return true;
        }
    }
    return false;
}

bool check(){
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= d; i++){
        if(!visited[i]){
            if(dfs(i, 0)){
                return true;
            }
        }
    }
    return false;
}


bool check1(){
    int tplt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= d; i++){
        if(!visited[i]){
            ++tplt;
            dfs(i);
        }
    }
    if(tplt == 1) return true;
    else return false;
}


main(){
    int t; cin >> t;
    while(t--){
       input();
       if(check() && check1()) cout << "YES\n";
       else cout << "NO\n";
    }
}