#include<bits/stdc++.h>
using namespace std;
main(){
    int n;
    cin >> n;
    int a[1001];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int sum = 0;
    for(int i = 1; i < 1001; i++){
        int x = a[0]/i;
        for(int j = 0; j < n; j++){
            int ok = 1;
            for(int k = 1; k <= a[j] + 1; k++){
                if(a[j]/k == x){
                    sum += k;
                    ok = 0;
                    break;
                }
            }
            if(ok){
                sum = 0;
                break;
            }
        }
        if(sum != 0) break;
    }
    cout << sum;
}