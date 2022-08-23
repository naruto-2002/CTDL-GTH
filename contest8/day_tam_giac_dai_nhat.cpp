#include<bits/stdc++.h>
using namespace std;
int r[100001], l[100001];
main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            r[i] = 1;
            l[i] = 1;
        }
        int ma = 0;
        for(int i = 1; i < n; i++)
            if(a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
        for(int i = n - 2; i >= 0; i--)
            if(a[i + 1] < a[i]) r[i] = r[i + 1] + 1;
        for(int i = 0; i < n; i++){
            if(l[i] + r[i] - 1 > ma) ma = l[i] + r[i] - 1;
        }

        cout << ma << endl;
    }
}