#include<bits/stdc++.h>
using namespace std;
main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<string> st;
        for(int i = s.size(); i >= 0; i--){
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^'){
                string fi = st.top(); st.pop();
                string se = st.top(); st.pop();
                string tmp = "(" + fi + s[i] + se +")";
                st.push(tmp);
            }else st.push(string(1, s[i]));
        } 
        cout << st.top() << '\n';
    }
}