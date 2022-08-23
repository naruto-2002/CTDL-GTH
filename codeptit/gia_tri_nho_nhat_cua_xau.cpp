#include<bits/stdc++.h>
using namespace std;
main(){
    long long t; cin >> t;
    while(t--){
        long long tt; cin >> tt;
        string s; cin >> s;
        priority_queue<long long, vector<long long>> q;
        long long a[300] = {0};
        for(long long i = 0; i < s.length(); i++){
            a[s[i]]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(a[s[i]] > 0){
                q.push(a[s[i]]);
                a[s[i]] = 0;
            }
        }
        while(tt > 0 && q.size() > 0){
            tt--;
            long long tmp = q.top(); q.pop();
            tmp -=  1;
            q.push(tmp);
        }
        long long res = 0;
        while(q.size() > 0){
            long long i = q.top(); q.pop();
            res += i*i;
        }
        cout << res << endl;

    }
}