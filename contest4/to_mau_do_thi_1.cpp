#include<bits/stdc++.h>
using namespace std;



int d, c, m;
int a[1005][1005];
int mau[1005];
int dem = 0;



void inp(){
    memset(a, 0, sizeof(a));
    memset(mau, 0, sizeof(m));
    cin >> d >> c >> m;
    while(c--){
        int x, y; cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
}



void slove(){
    int kt;
   for(int i = 1; i <= d; i++){
       if(!mau[i]){
           dem++;
           mau[i] = dem;
           for(int j = i + 1; j <= d; j++){
               if(a[i][j] == 0 && mau[j] == 0){
                   kt = 1;
                   for(int k = i + 1; k < j; k++){
                       if(a[k][j] && mau[i] == mau[k]){
                           kt = 0;
                           break;
                       }
                   }
                    if(kt) mau[j] = dem;
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