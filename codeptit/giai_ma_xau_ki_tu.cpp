#include<bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        stack<string> stt;
        string ans = "";
        int number = 0;
        for(int i = 0; i < s.length(); i++){
           if(s[i] >= '0' && s[i] <= '9'){
               number = number*10 + int(s[i] - '0');
           }else{
                if(number != 0) st.push(number);
                number = 0;
                if(s[i] == '[' && ans.length() != 0){
                    stt.push(ans);
                    ans = "";
                    s.erase(s.begin() + i);
                    i -= 1;
                     }else if(s[i] >= 'a' && s[i] <= 'z'){
                    ans += s[i];
                     }else if(s[i] == ']'){
                    if(ans.length() != 0){
                        stt.push(ans);
                        ans = "";
                    }
                    int n = 1;
                    if(st.size() != 0){
                        n = st.top(); st.pop();
                    }
                    string a = "", b = "";
                    if(stt.size() != 0){
                        a = stt.top(); stt.pop();
                    }
                    if(stt.size() != 0){
                        b = stt.top(); stt.pop();
                    }
                    string tmp = "";
                    while(n--) tmp += a;
                    tmp = b + tmp;
                    stt.push(tmp);
                    s.erase(s.begin() + i);
                    i -= 1;
                }
           }
        }
        cout << stt.top() << endl;
    }
}