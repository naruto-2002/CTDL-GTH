#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        vector<int> ans;
        while(n != 0){
            ans.push_back(n%10);
            n /= 10;
        }
        reverse(ans.begin(), ans.end());
        long long res = 0;
        for(int i = 0; i < ans.size(); i++){
            long long tmp = 0;
            for(int j = i; j < ans.size(); j++){
                tmp = tmp*10 + ans[j];
                res += tmp;
            }
        }
        cout << res << endl;
    }
}