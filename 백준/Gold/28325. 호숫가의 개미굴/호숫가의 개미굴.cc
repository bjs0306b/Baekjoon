#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v;
bool visited[250000];
long long dp[250000][2];
void input(){
    cin >> n;
    v.resize(n);
    for(long long i=0;i<n;i++){
        cin >> v[i];  
    }
}

void dfs(long long num){
    visited[num] = true;
    dp[num][0] = v[num]; 
    dp[num][1] = 1;

    if(!visited[(num-1+n)%n]){

        visited[(num-1+n)%n] = true;

        dfs((num-1+n)%n);

        dp[num][0] += max(dp[(num-1+n)%n][0], dp[(num-1+n)%n][1]);
        dp[num][1] += dp[(num-1+n)%n][0]; 
    }

    if(!visited[(num+1)%n]){

        visited[(num+1)%n] = true;

        dfs((num+1)%n);

        dp[num][0] += max(dp[(num+1)%n][0], dp[(num+1)%n][1]);
        dp[num][1] += dp[(num+1)%n][0]; 
    }
}

void solve(){
    dfs(0);

    cout << max(dp[0][1], dp[0][0]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}