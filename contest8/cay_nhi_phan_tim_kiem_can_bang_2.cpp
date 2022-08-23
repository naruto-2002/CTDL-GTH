#include<bits/stdc++.h>
using namespace std;

void slove(vector<int> M, int Left, int Right){
    if(Left >= Right) return;
    int mid = (Left + Right)/2;
    cout << M[mid] << ' ';
    slove(M, mid + 1, Right);
    slove(M, Left, mid);
}

main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> M(n);
        for(int i = 0; i < n; i++) cin >> M[i];
        sort(M.begin(), M.end(), greater< >());
        slove(M, 0, n);
        cout << '\n';
    }

}