#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		int* arr = new int[21];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(arr, arr + n);
		long long a = 0, b = 0;
		for(int i = 0; i < n; i++){
			if(i%2 == 0){
				a = a*10 + arr[i];
			}else{
				b = b*10 + arr[i];
			}
		}
		cout << (long long)a + b << endl;
		
	}
}