#include<bits/stdc++.h>
using namespace std;
long long money[100];
long long dem = 0;
long long n, s;
void Try(long long i){
    long long m = s;
    if(s >= 0){
        s -= money[i];
        dem++;
    }else{
        s += money[i];
        dem -= 1;
    }
    if(i == 0 || s == 0){
        return;
    }else{
        Try(i - 1);
    }
}
main(){
    cin >> n >> s;
    for(long long i = 0; i < n; i++) cin >> money[i];
    Try(n - 1);
    if(s != 0) cout << -1 << '\n';
    else cout << dem << "\n";
    
}