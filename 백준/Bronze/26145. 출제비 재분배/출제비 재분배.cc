#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> v(n+m, 0); for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n+m;j++){
            int num; cin >> num;
            v[i] -= num;
            v[j] += num;
        }
    }
    for(auto k : v) cout << k << " ";

    return 0;
}