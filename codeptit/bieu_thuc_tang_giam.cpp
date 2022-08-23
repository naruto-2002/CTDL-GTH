#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        string ss; cin >> ss;
        int len = ss.length();
        string s = "*" + ss;
        int a[1005];
        for(int i = 1; i <= len + 1; i++){
            a[i] = i;
        }
        for(int i = 1; i <= 20; i++){
            for(int j = 1; j <= len; j++){
                if(s[j] == 'D' && a[j] < a[j + 1]) swap(a[j], a[j + 1]);
            }
        }
        for(int i = 1; i <= len + 1; i++) cout << a[i];
        cout << endl;
        
    }
}