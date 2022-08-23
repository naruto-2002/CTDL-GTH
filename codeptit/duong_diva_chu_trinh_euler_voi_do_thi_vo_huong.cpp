#include<bits/stdc++.h>
using namespace std;
int a[1001][1001] = {0};
main(){
    int t; cin >> t;
    while(t--){
        int d, c; cin >> d >> c;
        memset(a, 0, sizeof(a));
        while(c--){
            int x, y; cin >> x >> y;
            a[x][y] = a[y][x] = 1;
        }
        int ch = 0, l = 0;
        for(int i = 1; i <= d; i++){
            int h = 0;
            for(int j = 1; j <= d; j++){
                h += a[i][j];
            }
            if(h%2 == 0) ch += 1;
            else l += 1;
        }
        if(ch == d) cout << 2 << '\n';
        else if(l == 2) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}