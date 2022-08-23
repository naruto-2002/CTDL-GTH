#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int len1, len2, len3; cin >> len1 >> len2 >> len3;
        string s1, s2, s3; cin >> s1 >> s2 >> s3;
        int dp[len1 + 5][len2 + 5][len3 + 5];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                for(int k = 1; k <= len3; k++){
                    if(s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]){
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }else{
                        dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                    }
                }
            }
        }
        cout << dp[len1][len2][len3] << endl;
    }
}