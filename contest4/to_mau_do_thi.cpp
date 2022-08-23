#include<bits/stdc++.h>
using namespace std;



int d, c, m;
vector<vector<int> > adj(1005);
int mau[1005];



void inp(){
    adj.clear();
    memset(mau, 0, sizeof(mau));
    cin >> d >> c >> m;
    while(c--){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}



void slove(){
    int kt;
    int dem = 0;
    for(int i = 1; i <= d; i++){
        if(!mau[i]){
            ++dem;
            mau[i]= dem;
            for(int j = i + 1; j <= d; j++){
                if(!binary_search(adj[i].begin(), adj[i].end(), j) && !mau[j]){
                    kt = 1;
                    for(int k : adj[j]){
                        if(mau[k] == mau[i]){
                            kt = 0;
                            break;
                        }
                        if(kt) mau[j] = dem;
                    }
                }
            }
        }
    }

   if(dem <= m) cout << "YES";
   else cout << "NO";
}



main(){
    int t; cin >> t;
    while(t--){
        inp();
        slove();
        cout << endl;
    }
}