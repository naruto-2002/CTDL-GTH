#include<bits/stdc++.h>

using namespace std;
map<string, int> mp_start, mp_end;

string left_clockwise(string s){
    return string({s[3], s[0], s[2], s[7], s[4], s[1], s[6], s[8], s[5], s[9]});
}

string right_clockwise(string s){
    return string({s[0], s[4], s[1], s[3], s[8], s[5], s[2], s[7], s[9], s[6]});
}

string left_counter_clockwise(string s){
    return string({s[1], s[5], s[2], s[0], s[4], s[8], s[6], s[3], s[7], s[9]});
}

string right_counter_clockwise(string s){
    return string({s[0], s[2], s[6], s[3], s[1], s[5], s[9], s[7], s[4], s[8]});
}

void clockwise(string s){
    queue<string> que; que.push(s);
    while(!que.empty()){
        string str = que.front(); que.pop();
        string status_1 = left_clockwise(str);
        string status_2 = right_clockwise(str);

        if(mp_start[status_1] == 0){
            que.push(status_1); 
            mp_start[status_1] = mp_start[str] + 1;
        }

        if(mp_start[status_2] == 0){
            que.push(status_2); 
            mp_start[status_2] = mp_start[str] + 1;
        }

        if(mp_start[que.back()] >= 14) break;
    }
}

int counter_clockwise(string s){
    queue<string> que; que.push(s);
    while(!que.empty()){
        string str = que.front(); que.pop();

        if(mp_start[str] != 0) return mp_start[str] + mp_end[str];

        string status_1 = left_counter_clockwise(str);
        string status_2 = right_counter_clockwise(str);

        if(mp_end[status_1] == 0){
            que.push(status_1); 
            mp_end[status_1] = mp_end[str] + 1;
        }

        if(mp_end[status_2] == 0){
            que.push(status_2); 
            mp_end[status_2] = mp_end[str] + 1;
        }
    }
    return -1;
}

void solve(){
    mp_start.clear(); mp_end.clear();
    string finish = "1238004765"; 
    string tmp;
    int n = 10;
    while(n--){
        char c; cin>>c;
        tmp.push_back(c);
    }

    clockwise(tmp);
    cout<<counter_clockwise(finish)<<endl;
}

int main(){
    int a; cin>>a;
    while(a--){
        solve();
    }
    return 0;
}
 

// HEXGAME
//
//HEXGAME là một trò chơi xếp hình gồm 10 miếng ghép hình lục giác đều, trên mỗi miếng ghép được điền một số nguyên, có 8 miếng được điền số  từ 1 đến 8 và có hai miếng điền số 0. Các miếng liên kết với nhau tạo thành lưới tổ ong. Ban đầu các miếng ghép ở vị trí như hình vẽ. Tại mỗi bước, chọn một miếng ghép có đúng 6 miếng ghép kề cạnh làm tâm, rồi xoay một nấc 6 miếng ghép kề cạnh đó theo chiều kim đồng hồ. Như vậy chỉ có hai cách chọn tâm, đó là chọn tâm bên trái và chọn tâm bên phải.
//
//
//
//Yêu cầu: Cho một trạng thái của trò chơi (nhận được sau một dãy biến đổi từ trạng thái ban đầu), hãy tính số phép biến đổi ít nhất để đưa về trạng thái ban đầu.
//
//Input:
//
//Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm:
//Dòng đầu tiên chứa 3 số ở 3 miếng ghép dòng thứ nhất (thứ tự từ trái qua phải).
//Dòng thứ hai chứa 4 số ở 4 miếng ghép dòng thứ hai (thứ tự từ trái qua phải).
//Dòng thứ 3 chứa 3 số ở 3 miếng ghép dòng thứ ba (thứ tự từ trái qua phải).
//Output: 
//
//Với mỗi bộ test in ra một số nguyên là số phép biến đổi ít nhất để đưa được về trạng thái ban đầu.
// 
//
//Ví dụ:
//
// 
//
//Input
//
//Output
//
//1
//
//1 0 2
//
//8 6 0 3
//
//7 5 4
//
//5