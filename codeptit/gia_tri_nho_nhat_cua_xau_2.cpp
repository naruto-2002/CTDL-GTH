#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b){
    return a > b;
}
main(){
    long long t; cin >> t;
    while(t--){
        long long k;
        string s;
        cin >> k >> s;
        long long a[150] = {0};
        for(long long i = 0; i < s.length(); i++){
            a[s[i]] += 1;
        }
        sort(a, a + 150, cmp);
        while(k--){
            sort(a, a + 150, cmp);
            a[0] -= 1;
        }
        long long res = 0;
        for(long long i = 0; i < 150; i++){
            if(a[i] != 0){
                res += (long long)a[i]*a[i];
            }
        }
        cout << res << endl;
    }
}