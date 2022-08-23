#include<bits/stdc++.h>
using namespace std;

main(){
    int n, s; cin >> n >> s;
    int a[105] = {0}, b[105] = {0};
    int ss = s;
    int sss = s;
    s -= 1;

    for(int i = n - 1; i >= 0; i--){
        if(s >= 9){
            a[i] = 9;
            s -= 9;
        }else{
            if(i == 0){
                a[i] = s + 1;
            }else{
                a[i] = s, s = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(ss >= 9){
            b[i] = 9;
            ss -= 9;
        }else{
            b[i] = ss, ss = 0;
            break;
        }
    }

    if(sss == 0 || sss > 9*n) cout << -1 << ' ' << -1 << endl;
    else{
        for(int i = 0; i < n; i++) cout << a[i];
        cout << ' ';
        for(int i = 0; i < n; i++) cout << b[i];
        cout << endl;
    }

}