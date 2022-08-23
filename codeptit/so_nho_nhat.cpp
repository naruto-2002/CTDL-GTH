#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int s, d; cin >> s >> d;
        if(d*9 < s) cout << -1;
        else{
            int res[100000];
            s--;
            for(int i = d-1; i >= 0; i--){
                if(s >= 9){
                    res[i] = 9;
                    s -= 9;
                }else{
                    if(i == 0) res[i] = s + 1;
                    else res[i] = s;
                    s = 0;
                }
            }
            for(int i = 0; i < d; i++) cout << res[i];
        }
        cout << endl;
    }
}