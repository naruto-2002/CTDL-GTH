#include<bits/stdc++.h>
using namespace std;
main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int a[n + 5];
        int b[n + 5];
        int c[n + 5];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
            c[i] = a[i];
        }
        for(int i = 1; i < n; i++) b[i] = max(b[i], b[i - 1]);
        for(int i = n - 2; i >= 0; i--) c[i] = min(c[i], c[i + 1]);
        int cnt = 0;
        for(int i = 0; i < n - 1; i++){
            if(b[i] <= c[i + 1]) cnt++;
        }
        cout << cnt << endl;
        for(int i = 0; i < n - 1; i++){
            if(b[i] <= c[i + 1]) cout << i + 1 << ' ';
        }
        cout << endl;
    }
}