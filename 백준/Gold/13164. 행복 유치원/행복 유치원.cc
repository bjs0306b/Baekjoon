#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<int> v(n), dif(n-1);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i) dif[i-1] = v[i] - v[i-1];
    }
    sort(dif.begin(), dif.end());
    long long ans = 0;
    for(int i=0;i<n-k;i++) ans += dif[i];
    cout << ans;

    return 0;
}