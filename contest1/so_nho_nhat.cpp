#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int i = 9;
        vector<int> res;
        while(n != 0 && res.size() != m){
            n -= i;
            if(n > 0 && res.size() < m){
                res.push_back(i);
            }else{
                n += i; 
                i--;
            }
        }
        if(i == 9) cout << -1;
        else{
            res[res.size() - 1] += 1;
            for(int i = res.size() - 1; i >= 0; i--){
                cout << res[i];
            }
        }
        cout << endl;
    }
}