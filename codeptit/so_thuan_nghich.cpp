#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int l = s.length();
        int res = 0;
        for(int i = 0; i < l; i++){
            for(int j = i; j < l; j++){
                bool ok = true;
                int k, h;
                for(k = i, h = j; k <= j, h >= i; k++, h--){
                    if(s[k] != s[h]){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    res = max(res, j - i + 1);
                }
            }
        }
        cout << res << endl;
    }
}