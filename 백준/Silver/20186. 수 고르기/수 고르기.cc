#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<long long> v(n); for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    long long ans = 0;
    for(int i=0;i<k;i++) ans += v[i];
    ans -= (k * (k-1) / 2);

    cout << ans;
    
    return 0;
}