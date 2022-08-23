#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int a[n], b[ n] = {0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = 1;
        }
        for(int i = 1; i < n; i++){
            b[i] = 1;
            for(int j = i - 1; j >= 0; ){
                if(a[i] >= a[j]){
                    b[i] += b[j];
                    j -= b[j];
                }
                else break;
            }
        }
        for(auto x : b) cout << x << ' ';
        cout << endl;
    }
}