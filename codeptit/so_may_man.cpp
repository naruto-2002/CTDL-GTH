#include<bits/stdc++.h>
using namespace std;
//string slove(int n){
//    queue<string> q;
//    q.push("4");
//    while(q.size() > 0){
//        string res = q.front(); q.pop();
//        long long sum = 0;
//        for(int  i = 0; i < res.size(); i++){
//            sum += (int)(res[i] - '0');
//        }
//        if(sum == n) return res;
//        q.push(res + "4");
//        q.push(res + "7");
//    }
//
//}
//main(){
//    int t; cin >> t;
//    while(t--){
//        int n; cin >> n;
//        if(n < 11 && n != 4 && n != 7) cout << -1;
//        else cout << slove(n);
//        cout << '\n';
//    }
//
//}
void outp(int a, int b){
    for(int i = 1; i <= a; i++) cout << 4;
    for(int i = 1; i <= b; i++) cout << 7;
}
main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 0; i <= n; i++){
            if(4*i < n && (n - 4*i)%7 == 0){
                a = i;
                b = (n - 4*i)/7;
                break;
            }
        }

        for(int i = 0; i <= n; i++){
            if(7*i < n && (n - 7*i)%4 == 0){
                c = (n - 7*i)/4;
                d = i;
            }
        }
        if(!a && !b && !c && !d) cout << -1;
        else{
            if(a + b == c + d){
            if(a >= c) outp(a, b);
            else outp(c, d);
            }
            else if(a + b < c + d){
                outp(a, b);
            }
            else if(a + b > c + d){
                outp(c, d);
            }
        }

        cout << '\n';
    }
}