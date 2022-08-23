#include<iostream>
#include<string>
#include<algorithm>
#define mod				 1000000007
#define ll				 long long
#define	p(x)			 pair<x,x> 
#define v(x)			 vector<x>
#define tree			 node*
#define pb(a)			 push_back(a)
#define pf(a)			 push_front(a)
#define FOR(i,l,r)		 for(int i=l;i<r;i++)
#define FORX(i,l,r,x)	 for(int i=l;i<r;i+=x)
#define FORD(i,l,r)		 for(int i=l;i>=r;i--)
#define correct(x,y,n,m) 0<=(x)&&(x)<(n)&&0<=(y)&&(y)<(m)
#define cin(M,n)		 FOR(i,0,n)cin>>M[i]
#define cout(M,n)		 FOR(i,0,n)cout<<M[i]<<" "
#define rs(M,x)		     memset(M,x,sizeof(M))
#define reset()			 FOR(i, 0, 1000001)A[i].clear(),check[i]=false
#define faster()		 cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()			 int t; cin >> t; while (t--)
#define pq(x )			 priority_queue<x>
#define neg_pq(x)		 priority_queue<x, vector<x>, greater<x>>
#define all(M)			 M.begin(),M.end()
using namespace std;



int main() {
	faster();

	string s; cin >> s;
	int q; cin >> q;
	while (q--) {
		char c; cin >> c;
		if (c == 'q') {
			int l, r; cin >> l >> r;
			string tmp = s;
			reverse(tmp.begin() + l - 1, tmp.begin() + r);
			if (tmp == s)cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			int u; cin >> u;
			char x; cin >> x;
			s[u - 1] = x;
		}
	}

}

//TRUY VẤN ĐỐI XỨNG
//
//Cho số nguyên S gồm N chữ số. Có Q truy vấn, mỗi truy vấn thuộc một trong hai loại sau:
//
//q L R: yêu cầu xác định xâu con S[L, L+1, …, R] có phải là một xâu đối xứng hay không?
//
//c U x: thay đổi kí tự thứ U thành chữ số x.
//
//Input
//
//Dòng đầu tiên chứa số nguyên S gồm N kí tự (N  <= 10^5).
//Tiếp theo là số lượng truy vấn Q (Q <= 10^5)
//Q dòng tiếp theo, mỗi dòng gồm một loại truy vấn.
//Output
//
//Với mỗi truy vấn loại 1, nếu xâu con là một số đối xứng, hãy in ra “YES”, ngược lại in ra “NO”.
//Test ví dụ:
//
//Input
//
//Output
//
//12345
//
//5
//
//q 1 5
//
//q 5 5
//
//c 4 3
//
//q 3 5
//
//q 3 4
//
// 
//
//NO
//
//YES
//
//NO
//
//YES