#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
main(){
    int n; cin >> n;
    int a[n + 5];
    vector<int> c, l;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i%2 == 1) l.push_back(a[i]);
        else c.push_back(a[i]);
    }
    sort(l.begin(), l.end());
    sort(c.begin(), c.end(), cmp);
    int p = 0, q = 0;
    for(int i = 1; i <= n; i++){
        if(i%2 == 1) cout << l[p++] << ' ';
        else cout << c[q++] << ' ';
    }
    cout << '\n';
}