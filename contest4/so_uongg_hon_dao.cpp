#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> > &a, int i, int j, int row, int col){
    if(i < 0 || j < 0|| i > (row - 1) || j > (col - 1) || !a[i][j]){
        return;
    }
    if(a[i][j]){
        a[i][j] = 0;
        dfs(a, i, j + 1, row, col);
        dfs(a, i, j - 1, row, col);
        dfs(a, i + 1, j, row, col);
        dfs(a, i - 1, j, row, col);
        dfs(a, i + 1, j + 1, row, col);
        dfs(a, i - 1, j + 1, row, col);
        dfs(a, i + 1, j - 1, row, col);
        dfs(a, i - 1, j - 1, row, col);
    }
}

void countislands(vector<vector<int> > &a){
    int row = a.size();
    int col = a[0].size();
    int dem = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(a[i][j]){
                a[i][j] = 0;
                ++dem;
                dfs(a, i, j + 1, row, col);
                dfs(a, i, j - 1, row, col);
                dfs(a, i + 1, j, row, col);
                dfs(a, i - 1, j, row, col);
                dfs(a, i + 1, j + 1, row, col);
                dfs(a, i - 1, j + 1, row, col);
                dfs(a, i + 1, j - 1, row, col);
                dfs(a, i - 1, j - 1, row, col);
            }
        }
    }
    cout << dem << '\n';
}

main(){
    int t; cin >> t;
    while(t--){
        int r, c; cin >> r >> c;
        vector<vector<int> > a;
        for(int i = 0; i < r; i++){
            vector<int> v;
            for(int j = 0; j < c; j++){
                int tmp; cin >> tmp;
                v.push_back(tmp);
            }
            a.push_back(v);
        }
        countislands(a);
    }
}