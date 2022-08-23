#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n + 1];
        bool ok = true;
        for(int i = 1; i <= k; i++){
             cin >> a[i];
             if(a[i] != i) ok = false;
        }
        if(ok){
            for(int i = n - k + 1; i <= n; i++) cout << i << ' ';
        }else{
            for(int i = k; i >= 1; i--){
                if(a[i] != a[i - 1] + 1){
                    a[i]--;
                    if(a[k] != n){
                        for(int j = i + 1; j <= k; j++){
                            a[j] += 1;
                        }
                    }
                    break;
                }
            }
            for(int i = 1; i <= k; i++) cout << a[i] << ' ';
        }
        cout << '\n';

    }
}