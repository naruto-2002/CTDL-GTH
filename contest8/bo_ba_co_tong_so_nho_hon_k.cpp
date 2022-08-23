#include<bits/stdc++.h>
using namespace std;
#define ll long long

main(){
    int t; cin >> t;
    while(t--){
        ll n, k, res = 0; cin >> n >> k;
        ll a[n + 1];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                res += lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - (a) - (j + 1);
            }
        }
        cout << res << endl;
    }
}