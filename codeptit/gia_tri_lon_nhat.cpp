#include<bits/stdc++.h>
using namespace std;

main(){
    int n; cin >> n;
    int x;
    long long sum = 0;
    while(n--){
        cin >> x;
        if(x > 0) sum += 2*x;
    }
    cout << sum;
}