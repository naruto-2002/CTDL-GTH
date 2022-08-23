#include<iostream>
#include<queue>
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
typedef node* tree;


void add_Node(tree& T, int u, int v, char c) {
	if (T == NULL) {
		T = new node(u);
		node* p = new node(v);
		if (c == 'L')T->pLeft = p;
		else T->pRight = p;
	}
	else {
		if (T->data == u) {
			node* p = new node(v);
			if (c == 'L')T->pLeft = p;
			else T->pRight = p;
		}
		else {
			if (T->pLeft != NULL)add_Node(T->pLeft, u, v, c);
			if (T->pRight != NULL)add_Node(T->pRight, u, v, c);
		}
	}
}

void Load(tree T) {
	queue<tree> X;
	X.push(T);
	while (X.size()) {
		tree tmp = X.front();
		X.pop();
		cout << tmp->data << " ";
		if (tmp->pLeft != NULL)X.push(tmp->pLeft);
		if (tmp->pRight != NULL)X.push(tmp->pRight);
	}
}



int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		tree T = NULL;
		for (int i = 0; i < n; i++) {
			int u, v;
			char c;
			cin >> u >> v >> c;
			add_Node(T, u, v, c);
		}
		Load(T);
		cout << endl;
	}
	return 0;
}



//DUYỆT CÂY THEO MỨC
//
//Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo Level-order. Phép duyệt level-order trên cây là phép thăm node theo từng mức của cây. Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt level-order: 20  8  22  4  12  10  14.
//
//
//
//    Input:
//
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
//T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
//Output:
//
//Đưa ra kết quả phép duyệt level-order theo từng dòng.
//     Ví dụ:
//
//Input
//
//Output
//
//2
//2
//1 2 R 1 3 L
//4
//10 20 L 10 30 R 20 40 L 20 60 R
//
//1 3 2
//
//10 20 30 40 60