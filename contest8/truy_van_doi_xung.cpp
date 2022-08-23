#include<bits/stdc++.h>
using namespace std;

main(){
    string s; cin >> s;
    int t; cin >> t;
    while(t--){
        char q; cin >> q;
        if(q == 'q'){
            int l, r; cin >> l >> r;
            string tmp = s;
            reverse(tmp.begin() + l - 1, tmp.begin() + r);
            if(tmp == s) cout << "YES\n";
            else cout << "NO\n";

        }else{
            int u;
            char x;
            cin >> u >> x;
            s[u - 1] = x;
        }
    }
}  