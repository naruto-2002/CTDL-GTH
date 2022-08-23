#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define arr vector<ll>
#define matr vector<vector<ll>>
int n;

matr tich(matr a, matr b){
    matr c(n, vector<ll> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
            for(int k = 0; k < n; k++){
                c[i][j] += ((a[i][k])%mod) * ((b[k][j])%mod);
                c[i][j] %= mod;
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

matr Pow(const matr &mt, ll n){
    if(n%2 == 0 && n > 2)
        return Pow(Pow(mt, n/2), 2);
    else if(n%2 && n > 2)
        return tich(Pow(Pow(mt, n/2), 2), mt);
    else if(n == 2)
        return tich(mt, mt);
    else
        return mt;
}

main(){
    int t; cin >> t;
    while(t--){
        ll k; cin >> n >> k;
        matr a(20, vector<ll> (20));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        matr ans = Pow(a, k);
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++){
                ll res = ans[i][j];
                cout << res << ' ';
            }
            cout << '\n';
        }
    }

}