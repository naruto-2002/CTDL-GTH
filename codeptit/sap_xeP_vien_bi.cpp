#include<bits/stdc++.h>
using namespace std;

main(){
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, t = 0, d = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'X') x++;
        else if(s[i] == 'T') t++;
        else d++;
    }
    int dem = 0;
    for(int i = n - d; i < n; i++){
        if(s[i] != 'D') dem++;
    }
    for(int i = 0; i < x; i++){
        if(s[i] != 'X') dem++;
    }
    int a = 0, b = 0;
    for(int i = n - d; i < n; i++){
        if(s[i] == 'X') a++;
    }
    for(int i = 0; i < x; i++){
        if(s[i] == 'D') b++;
    }
    cout << dem - min(a, b);

}