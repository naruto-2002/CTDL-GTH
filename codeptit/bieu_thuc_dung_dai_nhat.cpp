#include<bits/stdc++.h>
using namespace std;


main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int tt = 20;
        int ans = 0;
        while(tt--){
            stack<int> st;
            st.push(-1);
            int res = 0;
            int a = -1;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '(') st.push(i);
                else{
                    st.pop();
                    if(st.size() > 0){
                        if(i - st.top() > res){
                            res = i - st.top();
                            a = i;
                        }
                    }
                    if(st.size() == 0) st.push(i);
                }
            }
            if(a != -1) s.erase(s.begin() + a - res + 1, s.begin() + a + 1);
            ans += res;
        }
        cout << ans << endl;
    }
}