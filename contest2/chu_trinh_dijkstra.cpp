#include<bits/stdc++.h>
using namespace std;

int n, vt, a[1001][1001], d[1001];
set<int> T, V;

void input(){
    cin >> n >> vt;
    for(int i = 1; i <= n; i++){
        T.insert(i); V.insert(i);
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void dijkstra(int s){
    d[s] = 0;
}


main(){

}