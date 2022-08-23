#include<bits/stdc++.h>
using namespace std;

int d, c;
vector<int> ke[10005];
bool visited[10005];

void init(){
    cin >> d >> c;
    while(c--){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

int bfs(int u, int v){
    queue<pair<int, int>> q;
    q.push({u, 0});
    while(q.size() > 0){
        pair<int, int> tmp = q.front();
        q.pop();
        if(tmp.first == v){
            return tmp.second;
        }
        for(int x : ke[tmp.first]){
            if(!visited[x]){
                q.push({x, tmp.second + 1});
                visited[x] = true;
            }
        }
    }
    return -1;
}

main(){
    int t; cin >> t;
    while(t--){
        for(int i = 0; i <= 10005; i++) ke[i].clear();
        init();
        int res = 0, cnt = 0;
        for(int i = 1; i <= d; i++){
            for(int j = 1; j <= d; j++){
                memset(visited, false, sizeof(visited));
                if(i != j){
                    int f = bfs(i, j);
                    if(f != -1){
                        res += f, cnt++;
                    }
                }
            }
        }
        cout << setprecision(2) << fixed << res*1.0/cnt << endl;
    }
}

