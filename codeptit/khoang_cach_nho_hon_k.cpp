#include<bits/stdc++.h>
using namespace std;
main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        long long res = 0;
        sort(a, a + n);
        for(int i = 0; i < n - 1; i++){
           int tmp = a[i] + k;
           int vt = lower_bound(a, a + n, tmp) - a;
           int c = vt - i - 1;
           if(c >= 1) res += c;
        }
        cout << res << endl;
    }
}