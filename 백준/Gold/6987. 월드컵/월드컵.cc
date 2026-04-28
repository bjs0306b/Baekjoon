#include<bits/stdc++.h>
using namespace std;

int ans[6][3], cur[6][3];
vector<pair<int,int>> v;
bool is_possible;

void input(){
    for(int i=0;i<6;i++) for(int j=0;j<3;j++){cin >> ans[i][j]; cur[i][j] = 0;}
    is_possible = false;
}

void dfs(int n){
    if(is_possible) return;

    if(n == 15){
        bool flag = true;
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                if(ans[i][j] != cur[i][j]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) is_possible = true;
        return;
    }

    auto temp = v[n];
    int a = temp.first, b = temp.second;

    // a가 이김
    cur[a][0]++; cur[b][2]++;
    dfs(n+1);
    cur[a][0]--; cur[b][2]--;
    
    // b가 이김
    cur[b][0]++; cur[a][2]++;
    dfs(n+1);
    cur[b][0]--; cur[a][2]--;

    // 비김
    cur[a][1]++; cur[b][1]++;
    dfs(n+1);
    cur[a][1]--; cur[b][1]--;
}

void solve(){
    dfs(0);
    if(is_possible) cout << "1 ";
    else cout << "0 ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    for(int i=0;i<5;i++){
        for(int j=i+1;j<6;j++){
            v.push_back({i,j});
        }
    }

    int t = 4;
    while(t--){
        input();
        solve();
    }

    return 0;
}