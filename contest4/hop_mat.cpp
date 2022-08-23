#include<bits/stdc++.h>
using namespace std;

int k, d, c;
vector<int> adj[1005];
bool check[1005];
vector<int> ans;
int cnt[1005];
void inp(){
    cin >> k >> d >> c;
    for(int i = 1; i <= k; i++){
        int vt; cin >> vt;
        ans.push_back(vt);
    }
    while(c--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(cnt, 0, sizeof(cnt));
}

void loang(int u){
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!check[v]){
            check[v] = true;
            cnt[v]++;
            loang(v);
        }

    }
}


main(){
    inp();
    for(int i = 0; i < ans.size(); i++){
        memset(check, false, sizeof(check));
        check[ans[i]] = true;
        cnt[ans[i]] += 1;
        loang(ans[i]);
    }
    int res = 0;
    for(int i = 1; i <= d; i++){
        if(cnt[i] == k) res++;
    }
    cout << res << endl;
}