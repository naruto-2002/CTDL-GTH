#include<bits/stdc++.h>
using namespace std;
int vt(vector<int> a, int x){
    for(int i = 0; i < a.size(); i++){
        if(x == a[i]) return i;
    }
    return -1;
}
main(){
    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        vector<int> a,b,c;
        cin >> s1 >> s2;
        for(int i = 0; i < s1.length(); i++){
            a.push_back(int(s1[i] - '0'));
        }
        for(int i = 0; i < s2.length(); i++){
            b.push_back(int(s2[i] - '0'));
        }
        for(int i = 0; i < a.size(); i++){
            int t = vt(b, a[i]);
            if(t != -1){
                c.push_back(t);
            }
        }
        int res = 0, dp[2001] = {0};
        for(int i = 0; i < c.size(); i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(c[i] > c[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }



}