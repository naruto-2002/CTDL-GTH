#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n + 1];
        for(int i = 0; i < n; i++) cin >> a[i];
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] + a[j] == k) res += 1;
            }
        }
        cout << res << endl;
    }
}