#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, cmp);
        int l = 0, r = n/2, res = 0;
        while(l < n/2 && r < n){
            if(a[l] >= 2*a[r]){
                l++, r++, res++;
            }else{
                r++;
            }
        }
        cout << n - res << endl;
    }
}