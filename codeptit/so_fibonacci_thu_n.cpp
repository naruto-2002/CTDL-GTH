#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll n;
ll F[2][2], M[2][2];

void mul(ll f[2][2], ll m[2][2]){
    ll x = (f[0][0]*m[0][0]%mod + f[0][1]*m[1][0]%mod)%mod;
    ll y = (f[0][0]*m[0][1]%mod + f[0][1]*m[1][1]%mod)%mod;
    ll z = (f[1][0]*m[0][0]%mod + f[1][1]*m[1][0]%mod)%mod;
    ll t = (f[1][0]*m[0][1]%mod + f[1][1]*m[1][1]%mod)%mod;
    F[0][0] = x; F[0][1] = y;
    F[1][0] = z; F[1][1] = t;


    //for(int i = 0; i <= 1; i++){
    //    for(int j = 0; j <= 1; j++){
    //        ll ans = 0;
    //        for(int k = 0; k <= 1; k++){
    //            ans += (ll)f[i][k]*m[k][j]%mod;
    //        }
    //        F[i][j] = ans%mod;
    //    }
    //}
}

void Pow(ll f[2][2], ll n){
    if(n <= 1) return;
    Pow(f, n/2);
    mul(f,f);
    if(n&1) mul(f, M);
}

void slove(){
    F[0][0] = F[0][1] = F[1][0] = 1;
    F[1][1] = 0;
    M[0][0] = M[0][1] = M[1][0] = 1;
    M[1][1] = 0;

    cin >> n;
    if(n == 0){
        cout << 0;
    }else{
        Pow(F, n - 1);
        cout << F[0][0];
    }
    cout << '\n';
}

main(){
    int t; cin >> t;
    while(t--){
        slove();
    }
}

