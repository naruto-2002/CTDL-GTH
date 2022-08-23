#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

        char s[1005];

        for(int i = 0; i < n; i++){
            cin >> s[i];
//            cout << s[i] << ' ';
        }
		stack<int> S;
		for (int i = 0; i < n; i++) {
			if (s[i] >= '0' && s[i] <= '9') S.push(s[i] + 48);
			else {
				int a = S.top(); S.pop();
				int b = S.top(); S.pop();

                if(s[i] == '+'){
                    S.push(b + a);
                }else if(s[i] == '-'){
                    S.push(b - a);
                }else if(s[i] == '*'){
                    S.push(b*a);
                }else if(s[i] == '/'){
                    S.push(b/a);
                }
			}
		}
		cout << S.top() << endl;
        
	}
}

