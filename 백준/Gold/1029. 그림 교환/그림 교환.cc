#include <bits/stdc++.h>
using namespace std;

int n, dp[15][15][1<<15], A[15][15];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<n;j++) A[i][j] = s[j] - '0';
    }
    memset(dp, -1, sizeof(dp));
}

int dfs(int cur, int price, int visited){
    int& ret = dp[cur][price][visited];
    if(ret != -1) return ret;
    ret = 1;
    for(int i=0;i<n;i++){
        if(cur == i || A[cur][i] < price || (visited & (1 << i)) != 0) continue;
        ret = max(ret, dfs(i, A[cur][i], visited | (1 << i)) + 1);
    }
    return ret;
}

void solve(){
    cout << dfs(0,0,1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}