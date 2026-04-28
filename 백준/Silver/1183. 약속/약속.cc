#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++){int a,b; cin >> a >> b; v[i] = a-b;}
    sort(v.begin(), v.end());

    if(n%2) cout << 1;
    else cout << v[n/2] - v[n/2-1] + 1;

    return 0;
}