#include <bits/stdc++.h>
using namespace std;

long long ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){int num; cin >> num; ans += num;}
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        ans += v[i] * i;
    }
    cout << ans;

    return 0;
}