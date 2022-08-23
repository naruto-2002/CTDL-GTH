#include<bits/stdc++.h>
using namespace std;

int d, c;
int a[1005][1005];

void inp(){
    memset(a, 0, sizeof(a));
    cin >> d >> c;
    for(int i = 0; i < c; i++){
        int x, y; cin >> x >> y;
        a[x][y] = 1;
    }
}

int euler(){
    for(int i = 1; i <= d; i++){
        int x = 0, y = 0;
        for(int j = 1; j <= d; j++){
            if(a[i][j]) x++;
            if(a[j][i]) y++;
        }
        if(x != y) return 0;
    }
    return 1;
}

main(){
    int t; cin >> t;
    while(t--){
        inp();
        cout << euler() << endl;
    }
}