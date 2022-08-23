#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;

main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        long long a[1001];
        long long dp[1001];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                if(i >= a[j]) dp[i] += dp[i - a[j]]%mod;
                dp[i] %= mod;
            }
        }
        cout << dp[k] << endl;
    }
}