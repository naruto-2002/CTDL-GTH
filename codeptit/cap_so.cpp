#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;
            a.push_back({x, y});
        }
        sort(a.begin(), a.end(), cmp);
        int dp[105] = {0};
        int res = 0;
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(a[i].first > a[j].second) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
}