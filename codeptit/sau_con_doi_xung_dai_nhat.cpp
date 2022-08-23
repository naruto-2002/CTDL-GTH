#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                int k, h;
                int ok = 1;
                for(k = i, h = j; k <= j, h >= i; k++, h--){
                    if(s[k] != s[h]){
                        ok = 0;
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