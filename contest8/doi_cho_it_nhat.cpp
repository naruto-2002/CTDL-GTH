#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n, res = 0; cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n - 1; i++){
            int k = i;
            for(int j = i + 1; j <= n; j++){
                if(a[k] > a[j]){
                    k = j;
                }
            }
            if(k != i) res += 1;
            swap(a[i], a[k]);
        }
        cout << res << endl;
    }
}