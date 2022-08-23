#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool slove(ll n, ll k, ll a[]){
    multiset<ll> s;
    for(int i = 1; i <= n; i++) s.insert(a[i]);
    for(int i = 0; i <= n; i++){
        if(s.count(a[i] + k) != 0) return true;
    }
    return false;
}

main(){
    int t; cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[n + 5] = {0};
        bool ok = false;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] == 0) ok = true;
        }
        for(int i = 1; i <= n; i++) a[i] += a[i - 1];
        if(k == 0){
            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }else{
            if(slove(n, k, a)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}