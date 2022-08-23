#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
main(){
    int t; cin >> t;
    while(t--){
        string s, ss; cin >> s >> ss;
        int res = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= ss.length(); j++){
                if(s[i - 1] == ss[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        cout << res << endl;
    }
}
