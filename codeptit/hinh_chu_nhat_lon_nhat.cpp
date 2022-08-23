#include<bits/stdc++.h>
using namespace std;
#define ll long long

main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n + 5] = {0};
        ll res = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 0; i <= n; i++){
            int cnt = 1;
            ll ans = 0;
            for(int j = i + 1; j <= n + 1; j++){
                if(a[j] >= a[i]) cnt += 1;
                else{
                    ans = max(ans, a[i]*cnt);
                    break;
                }
            }
            int cntt = 1;
            ll anss = 0;
            for(int j = i - 1; j >= 0; j--){
                if(a[j] >= a[i]) cntt += 1;
                else{
                    anss = max(anss, a[i]*cntt);
                    break;
                }
            }
            res = max(res, ans + anss - a[i]);
        }
        cout << res << endl;
    }
}