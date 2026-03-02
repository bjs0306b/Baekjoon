#include <bits/stdc++.h>
using namespace std;

vector<char> c[2];
int n;
vector<bool> is_dif;

void input(){
    cin >> n;
    for(int i=0;i<2;i++){
        c[i].resize(n);
        for(int j=0;j<n;j++) cin >> c[i][j];
    }
    is_dif.resize(n);
    for(int i=0;i<n;i++){
        if(c[0][i] != c[1][i]) is_dif[i] = true;
        else is_dif[i] = false;
    }
}

void solve(){
    int ans = INT32_MAX;
    // 처음 꺼 안눌렀음.
    vector<bool> temp(n, false);
    int cnt = 0;
    for(int i=1;i<n-1;i++){
        // i-1번째 전구는 이제 i번째 스위치를 통해서만 변경이 가능해짐. 따라서 is_dif와 다르면 반드시 눌러야 함.
        if(is_dif[i-1] != temp[i-1]){ // 누름
            cnt++;
            for(int j=-1;j<=1;j++) temp[i+j] = !temp[i+j];
        }
    }
    bool flag1 = is_dif[n-2] == temp[n-2], flag2 = is_dif[n-1] == temp[n-1];
    if(flag1 && flag2) ans = min(ans, cnt);// 마지막 꺼 안눌러도 됨.
    else if(!flag1 && !flag2) ans = min(ans, cnt+1);// 마지막 꺼 눌러야 됨.
    // 이외에는 불가능

    // 처음 꺼 눌렀음.
    temp.assign(n, false);
    cnt = 1; // 눌러서 1
    temp[0] = true, temp[1] = true; // 눌러서 0,1 번쨰 전구 바뀜.
    for(int i=1;i<n-1;i++){
        // i-1번째 전구는 이제 i번째 스위치를 통해서만 변경이 가능해짐. 따라서 is_dif와 다르면 반드시 눌러야 함.
        if(is_dif[i-1] != temp[i-1]){ // 누름
            cnt++;
            for(int j=-1;j<=1;j++) temp[i+j] = !temp[i+j];
        }
    }
    flag1 = is_dif[n-2] == temp[n-2], flag2 = is_dif[n-1] == temp[n-1];
    if(flag1 && flag2) ans = min(ans, cnt);// 마지막 꺼 안눌러도 됨.
    else if(!flag1 && !flag2) ans = min(ans, cnt+1);// 마지막 꺼 눌러야 됨.
    // 이외에는 불가능

    if(ans == INT32_MAX) cout << -1; // 두 경우 다 불가능
    else cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}