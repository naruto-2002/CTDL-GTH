#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
struct cmp{
   bool operator()(ll a, ll b){
       return a >= b;
   }
};
main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll val;
        priority_queue<ll, vector<ll>, cmp > q;
        for(int i = 0; i < n; i++){
            cin >> val;
            q.push(val);
        }
        ll res = 0;
        while(q.size() > 1){
            ll x = q.top(); q.pop();
            ll y = q.top(); q.pop();
            ll ans = x + y;
            res += ans%mod;
            res%=mod;
            q.push(ans%mod);
        }
        cout << res << endl;
        
    }
}