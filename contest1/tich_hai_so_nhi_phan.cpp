#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        long long a1 = 0, b1 = 0;
        int lena = a.length();
        for(int i = lena - 1; i >= 0; i--){
            if(a[i] == '1') a1 += pow(2, lena - 1 - i);
        }
        int lenb = b.length();
        for(int i = lenb - 1; i >= 0; i--){
            if(b[i] == '1') b1 += pow(2, lenb - 1 - i);
        }
        cout << a1*b1 << endl;
    }
}