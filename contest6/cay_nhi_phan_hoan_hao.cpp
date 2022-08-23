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
#define reset()			 FOR(i, 0, 1001)A[i].clear(),check[i]=false
#define faster()		 cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define run()			 int t; cin >> t; while (t--)
#define pq(x )			 priority_queue<x>
#define neg_pq(x)		 priority_queue<x, vector<x>, greater<x>>
#define all(M)			 M.begin(),M.end()
using namespace std;


struct node {
	int data;
	node* pLeft;
	node* pRight;
	node(int x) {
		this->data = x;
		pLeft = pRight = NULL;
	}
};


void Add(tree&T,int u,int v,char c) {
	if (T == NULL) {
		T = new node(u);
		tree p = new node(v);
		if (c == 'L')T->pLeft = p;
		else T->pRight = p;
	}
	else {
		if (T->data == u) {
			tree p = new node(v);
			if (c == 'L')T->pLeft = p;
			else T->pRight = p;
		}
		else {
			if (T->pLeft != NULL)Add(T->pLeft, u, v, c);
			if (T->pRight != NULL)Add(T->pRight, u, v, c);
		}
	}
}

set<int> S;
string res = "Yes";
void Load(tree T,int count) {
	if (T->pLeft && !T->pRight || T->pRight && !T->pLeft)res = "No";
	else if (!T->pLeft && !T->pRight) {
		S.insert(count);
		if (S.size() > 1)res = "No";
	}
	else {
		Load(T->pLeft, count + 1);
		Load(T->pRight, count + 1);
	}
}


int main(){
	faster();
	run() {
		S.clear();
		int n; cin >> n;
		tree T = NULL;
		FOR(i, 0, n) {
			int u, v; char c;
			cin >> u >> v >> c;
			Add(T, u, v, c);
		}
		res = "Yes";
		Load(T, 0);
		cout << res << endl;
	}
}


//CÂY NHỊ PHÂN HOÀN HẢO
//
//Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây hoàn hảo hay không (perfect tree)? Một cây nhị phân được gọi là cây hoàn hảo nếu tất cả các node trung gian của nó đều có hai node con và tất cả các node lá đều có cùng một mức.
//
//      Input:
//
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
//T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
//Output:
//
//Đưa ra kết quả mỗi test theo từng dòng.
//      Ví dụ:
//
//Input
//
//Output
//
//3
//6
//10 20 L 10 30 R 20 40 L 20 50 R 30 60 L 30 70 R
//2
//18 15 L 18 30 R
//5
//1 2 L 2 4 R 1 3 R 3 5 L 3 6 R
//
//Yes
//Yes
//No

