#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin>> t;
    while(t--){
        int n, x, y, z; cin >> n >> x >> y >> z;
        int dp[1005] = {0};
        dp[0] = 0;
        dp[1] = x;
        for(int i = 2; i <= n; i++){
            if(i&1) dp[i] = min(dp[i - 1] + x, dp[(i + 1)/2] + z + y);
            else dp[i] = min(dp[i - 1] + x, dp[i/2] + z );
        }
        cout << dp[n] << '\n';
    }
}