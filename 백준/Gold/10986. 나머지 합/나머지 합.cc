#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    vector<long long> v(n), mod(n+1), cnt(m, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    mod[0] = 0;
    for (int i = 0; i < n; i++)
        mod[i+1] = (mod[i] + v[i]) % m;
    for (int i = 0; i <= n; i++)
        cnt[mod[i]]++;
    for(int i=0;i<m;i++)
        ans += cnt[i]*(cnt[i]-1)/2;
    cout << ans;

    return 0;
}