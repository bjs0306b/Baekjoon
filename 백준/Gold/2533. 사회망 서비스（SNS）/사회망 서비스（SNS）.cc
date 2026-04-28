#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[1000000];
bool visited[1000000];
int dp[1000000][2];

void input(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int num){
    visited[num] = true;

    dp[num][0] = 0;
    dp[num][1] = 1;

    for(auto k : v[num]){
        if(visited[k]) continue;

        dfs(k);

        dp[num][0] += dp[k][1];
        dp[num][1] += min(dp[k][0], dp[k][1]);
    }
}

void solve(){
    dfs(0);
    cout << min(dp[0][0], dp[0][1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}