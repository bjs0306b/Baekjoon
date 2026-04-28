#include <bits/stdc++.h>
using namespace std;
deque<bool> dq[4];
bool visited[4];
void rotate_cw(int gear_num){
    dq[gear_num].push_front(dq[gear_num].back());
    dq[gear_num].pop_back();
}
void rotate_ccw(int gear_num){
    dq[gear_num].push_back(dq[gear_num].front());
    dq[gear_num].pop_front();
}

void rotate(int gear_num, bool dir){
    visited[gear_num] = true;

    if(gear_num - 1 >= 0 && !visited[gear_num-1] &&  dq[gear_num][6] != dq[gear_num-1][2])
        rotate(gear_num-1, !dir);
    if(gear_num + 1 < 4 && !visited[gear_num+1] &&  dq[gear_num][2] != dq[gear_num+1][6])
        rotate(gear_num+1, !dir);

    if(dir){ // CW
        rotate_cw(gear_num);
    }
    else{ // dir == 0, CCW
        rotate_ccw(gear_num);
    }
}

void check(){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            cout << dq[i][j];
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<4;i++){
        string s; cin >> s;
        for(int j=0;j<8;j++){
            if(s[j] == '1') dq[i].push_back(1);
            else dq[i].push_back(0);
        }
    }
    int n; cin >> n;    
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++) visited[j] = false;
        int num, dir; cin >> num >> dir; num--;
        if(dir == -1) dir = 0;
        rotate(num, dir);

        // check();
    }

    int ans = 0;
    int temp = 1;
    for(int i=0;i<4;i++){
        ans += dq[i][0] * temp;
        temp *= 2;
    }
    cout << ans;
    
    return 0;
}