#include<bits/stdc++.h>
using namespace std;

int prioritize(char c){
    if(c == '^') return 5;
    else if(c == '*' || c == '/') return 4;
    else if(c == '+' || c == '-') return 3;
    else return 2;
}

void slove(string s){
    int len = s.size();
    stack<char> st;
    for(int i = 0; i < len; i++){
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') cout << s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(st.size() && st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-'){
            while(st.size() && prioritize(st.top()) >= prioritize(s[i])){
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
     while(st.size()){
        if(st.top() == '(') st.pop();
        else{
            cout << st.top();
            st.pop();
        }
    }
}

main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        slove(s);
        cout << '\n';
    }

}