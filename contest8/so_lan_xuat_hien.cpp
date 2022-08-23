#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int res = 0;
        while(n--){
            int x; cin >> x;
            if(x == k) res += 1;
        }
        cout << (res == 0 ? -1 : res) << '\n';
    }
}