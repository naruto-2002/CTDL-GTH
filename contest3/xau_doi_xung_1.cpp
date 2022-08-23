#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1;
        int l = s1.length();
        s2 = s1;
        reverse(s2.begin(), s2.end());
        int dp[101][101];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for(int i = 1; i <= l; i++){
            for(int j = 1; j <= l; j++){
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        cout << l - res << endl;
    }
}