#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int dp[105][50005];
main(){
    for(int i = 0; i < 101; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <50005; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }
    for(int i = 1; i < 105; i++){
        for(int so = 0; so <= 9; so++){
            for(int j = so; j <= 50000; j++){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - so])%mod;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
}