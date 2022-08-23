#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int add, fir, sec;
}job;
bool cmp(job a, job b){
    return a.sec > b.sec;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        job a[n + 1];
        for(int i = 0; i < n; i++){
            cin >> a[i].add >> a[i].fir >> a[i].sec;
        }
        sort(a, a + n, cmp);

        int F[1005] = {0}, res = 0, d = 0;
        for(int i = 0; i < n; i++){
            while(F[a[i].fir] && a[i].fir > 0) a[i].fir -= 1;
            if(!F[a[i].fir] && a[i].fir > 0){
                F[a[i].fir] = 1;
                res += a[i].sec;
                d++;
            }
        }
        cout << d << ' ' << res << endl;
    }
}
