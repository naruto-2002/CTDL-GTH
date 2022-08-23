#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'T', 'N', 'B'};

char a[505][505];
bool check[505][505];
pair<int, int> v, u;
bool flag;

void dfs(int x, int y, int cnt = 0, char d = 'X')
{
    check[x][y] = true;
    if (x == v.first && y == v.second && cnt <= 3)
    {
        flag = true;
        return;
    }
    if (cnt > 3 || a[x][y] == 'T')
    {
        check[x][y] = false;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dx[i], y1 = y + dy[i];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] != '*' && !check[x1][y1])
        {
            if (d != dir[i])
                dfs(x1, y1, cnt + 1, dir[i]);
            else
                dfs(x1, y1, cnt, dir[i]);
        }
    }
    check[x][y] = false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                    u = {i, j};
                if (a[i][j] == 'T')
                    v = {i, j};
            }
        flag = false;
        memset(check, false, sizeof(check));
        dfs(u.first, u.second);
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

//
//TÌM ĐƯỜNG
//
//Cho một bảng S[][] kích thước N x M, bao gồm các ô trống, các vật cản. Ban đầu bạn ở vị trí S. Nhiệm vụ của bạn là hãy di chuyển tới vị trí T, sao cho số lần đổi hướng không quá hai lần.
//
//Input:
//
//Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N, M ≤ 500).
//N dòng tiếp theo, mỗi dòng gồm M kí tự mô tả bảng S. Trong đó: ‘.’ là một ô trống, ‘*’ là vật cản, ‘S’ là vị trí xuất phát và ‘T’ là vị trí đích. (Chỉ có một vị trí S và T duy nhất).
//Output: 
//
//Với mỗi test, in ra “YES” nếu tìm được đường đi, ra in “NO” trong trường hợp ngược lại.
//Ví dụ:
//
//Input:
//
//Output
//
//2
//
//5 5
//
//..S..
//
//****.
//
//T....
//
//****.
//
//.....
//
//5 5
//
//S....
//
//****.
//
//.....
//
//.****
//
//..T..
//
// 
//
//YES
//
//NO
//
// 