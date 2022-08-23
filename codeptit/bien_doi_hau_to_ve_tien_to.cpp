#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int len = s.size();
        stack<string> res;
        for(int i = 0; i < len; i++){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' || s[i] == '%'){
                string a = res.top(); res.pop();
                string b = res.top(); res.pop();
                string tmp = string(1, s[i]) + b + a;
                res.push(tmp);
            }else{
                res.push(string(1, s[i]));
            }
        }
        cout << res.top() << endl;
    }
}