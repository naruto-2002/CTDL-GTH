#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> stk;
        int xoa = 0, res = 0;
        for(int i = 0; i < s.size(); i ++){
            if(stk.size() == 0){
                stk.push(s[i]);
            }else if(stk.top() == '[' && s[i] == ']'){
                stk.pop();
                xoa += 2;
            }else if(stk.top() == ']' && s[i] == '['){
                res += stk.size() + xoa;
                stk.pop();
            }else if(s[i] == '['){
                stk.push(s[i]);
            }else if(stk.top() == ']' && s[i] == ']'){
                stk.push(s[i]);
            }
            if(stk.size() == 0) xoa = 0;
           
        }
        cout << res << endl;
    }
}