#include <bits/stdc++.h>
using namespace std;

int n,m;
long long ans;
vector<int> v, pre_sum;
map<int, long long> mp; // 누적합, cnt

void input(){
    cin >> n >> m;
    v.resize(n), pre_sum.resize(n+1);
    pre_sum[0] = 0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        pre_sum[i+1] = pre_sum[i] + v[i];
    }
}

void solve(){
    mp[0] = 1;
    for(int i=1;i<=n;i++){
        ans += mp[pre_sum[i] - m];
        mp[pre_sum[i]]++;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}