#include<bits/stdc++.h>
using namespace std;

long long slove(string s){
    long long i, j;
    long long res = 0;
    for(i = 0, j = s.size() - 1 ; i < s.size(), j >= 0; i++, j--){
        if(s[i] == '1'){
            res += pow(2, j);
        }
    }
    return res;
}

main(){
    long long t; cin >> t;
    while(t--){
        string s, ss; cin >> s >> ss;
        cout << slove(s)*slove(ss) << endl;
    }
}

