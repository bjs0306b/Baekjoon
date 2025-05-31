#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int k; cin >> k;
    int ans = 0;
    map<string, int> cnt;
    for(int i=0;i<n;i++){
        int zero_cnt = 0;
        for(auto k : v[i]) if(k == '0') zero_cnt++;

        if(zero_cnt > k || zero_cnt % 2 != k % 2)continue;
        ans = max(ans, ++cnt[v[i]]);
    }
    cout << ans;
    return 0;
}