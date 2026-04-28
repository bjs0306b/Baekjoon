#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    long long sum = 0;
    vector<long long> v(n); for(int i=0;i<n;i++){cin >> v[i]; sum += v[i];}
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += (sum - v[i]) * v[i];
    }
    cout << ans/2;
    
    return 0;
}