#include<bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        long long a[100000], res = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                res += lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - a - j - 1;
            }
        }
        cout << res << endl;
    }
}