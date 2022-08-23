#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> ans;
        while(n--){
            int u, v;
            char x;
            cin >> u >> v >> x;
            ans.insert(u);
            ans.insert(v);
        }
        for(int x : ans) cout << x << ' ';
        cout << endl;
       
    }
}