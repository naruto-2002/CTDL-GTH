#include<bits/stdc++.h>
using namespace std;

int n, vt, a[1001][1001];

void input(){
    cin >> n >> vt;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
}

void euler(int u){
    stack<int> st;
    vector<int> CE;
    st.push(u);
    while(st.size() > 0){
        int s = st.top();
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!a[s][i]) cnt += 1;
        }
        if(cnt != n){
            for(int i = 1; i <= n; i++){
                if(a[s][i]){
                    st.push(i);
                    a[s][i] = a[i][s] = 0;
                    break;
                }
            }
        }else{
            st.pop();
            CE.push_back(s);
        }
    }
    for(int i = CE.size() - 1; i >= 0; i--){
        cout << CE[i] << ' ';
    }
}


main(){
    input();
    euler(vt);
}