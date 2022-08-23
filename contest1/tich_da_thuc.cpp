#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    cin >> t;
    while(t--){
        map<int, int> P, Q, R;
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> P[i];
        }
        for(int i = 0; i < m; i++){
            cin >> Q[i];
        }
        int dem = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 R[i+j] += P[i]*Q[j];
            }
        }
        for(int i = 0; i <= (n - 1) + (m - 1); i++){
            cout << R[i] << ' ';
        }
        cout << endl;
    }


}