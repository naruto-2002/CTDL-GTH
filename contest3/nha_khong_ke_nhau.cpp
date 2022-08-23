#include<bits/stdc++.h>
using namespace std;
main(){
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long a[n+1];
        for(long long i = 1; i <= n; i++){
            cin >> a[i];
        }
        long long dp[1000001];
        dp[1] = a[1];
        dp[2] = max(a[1], a[2]);
        for(long long i = 3; i <= n; i++){
            dp[i] = max(dp[i-2] + a[i], dp[i-1]);
        }
        cout << dp[n] << endl;
    }
}
