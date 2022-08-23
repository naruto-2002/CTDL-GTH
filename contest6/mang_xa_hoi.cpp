#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> ke[10005], a;


void init(){
    for(int i = 0; i <= 10005; i++) ke[i].clear();
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        a.push_back(x);
    }
}

main(){
    int t; cin >> t;
    while(t--){
        init();
        int ok = 1;
        for(int i = 0; i < a.size(); i++){
            for(int x : ke[a[i]]){
                int ok1 = 0;
                int KT = 0;
                for(int y : ke[x]){
                    KT = 1;
                    for(int z : ke[a[i]]){
                        if(y == z) ok1 = 1;
                    }
                }
                if(ok1 == 0 && KT){
                    ok = 0;
                    break;
                }
            }
            if(ok == 0) break;
        }
        if(ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}