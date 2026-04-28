#include <bits/stdc++.h>
using namespace std;

int A[4];
set<int> clock_num;
void dfs(int dep){
    if(dep == 4){
        int mn = INT32_MAX;
        for(int i=0;i<4;i++){
            int sum = 0;
            for(int j=0;j<4;j++){
                sum += A[(i+j)%4] * pow(10, 3-j);
            }
            mn = min(mn, sum);
        }
        
        clock_num.insert(mn);
        return;
    }
    for(int i=1;i<10;i++){
        A[dep] = i;
        dfs(dep+1);
    }
}

void solve(){
    dfs(0);
    int temp[4]; for(int i=0;i<4;i++) cin >> temp[i];
    int mn = INT32_MAX;
    for(int i=0;i<4;i++){
        int sum = 0;
        for(int j=0;j<4;j++){
            sum += temp[(i+j)%4] * pow(10, 3-j);
        }
        mn = min(mn, sum);
    }
    int ans = 0;
    for(auto k : clock_num){
        ans++;
        if(k == mn){
            cout << ans;
            return;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    solve();

    return 0;
}