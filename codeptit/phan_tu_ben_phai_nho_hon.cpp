#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 5];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            int ok = 0;
            for(int j = i + 1; j < n; j++){
                if(a[j] > a[i]){
                    for(int k = j + 1; k < n; k++){
                        if(a[k] < a[j]){
                            ok = 1;
                            cout << a[k] << ' ';
                            break;
                        }
                        
                    }
                    break;
                }
            }
            if(ok == 0){
                cout << -1 << ' ';          
            }
        }
        cout << endl;
    }
}