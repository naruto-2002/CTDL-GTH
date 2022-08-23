#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include<string>
#include<climits>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define mod				 1000000007
#define ll				 unsigned long long
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
#define reset()			 FOR(i, 0, 100001)A[i].clear(),check[i]=false
#define faster()		 cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()			 int t; cin >> t; while (t--)
#define pq(x )			 priority_queue<x>
#define neg_pq(x)		 priority_queue<x, vector<x>, greater<x>>
#define all(M)			 M.begin(),M.end()
using namespace std;

//_______________________T_O_A_N________________________//

v(int) A[100001];
bool check[100001];
int res = 0;

void DFS(int u, int count) {
	res = max(res, count);
	check[u] = true;
	for (auto x : A[u])if (!check[x])DFS(x, count + 1);
}
int main() {
	faster();
	run() {
		reset();
		int n; cin >> n;
		FOR(i, 0, n - 1) {
			int u, v; cin >> u >> v;
			A[u].push_back(v);
		}
		res = 0;
		DFS(1, 0);
		cout << res << endl;
	}
	return 0;
}

//ĐỘ CAO CỦA CÂY
//
//Cho một cây có N node, gốc tại  1. Độ cao của một node u được tính bằng khoảng cách từ u tới node gốc. Độ cao của node gốc bằng 0. Nhiệm vụ của bạn là hãy tìm node xa node gốc nhất và in ra độ cao của node này.
//
//Input:
//
//Dòng đầu tiên là số lượng bộ test T( T≤ 20).
//
//Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 100 000).
//
//N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.
//
//Output: 
//
//Với mỗi test, in ra một số nguyên là độ cao của cây.
//
//Test ví dụ:
//
//Input:
//
//Output
//
//2
//
//5
//
//1 2
//
//1 3
//
//2 4
//
//2 5
//
//4
//
//1 2
//
//2 3
//
//3 4
//
// 
//
//2
//
//3