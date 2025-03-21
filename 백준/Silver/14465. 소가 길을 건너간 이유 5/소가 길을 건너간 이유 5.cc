#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,b; cin >> n >> k >> b;
    vector<bool> v(n, 1); for(int i=0;i<b;i++){int num; cin >> num; v[--num] = 0;}
    int ans = 0;
    
    int cnt = 0;
    for(int i=0;i<k;i++) if(v[i]) cnt++;
    ans = max(ans, cnt);

    for(int i=k;i<n;i++){
        cnt += v[i];
        cnt -= v[i-k];
        ans = max(ans, cnt);
    }
    cout << k - ans;

    return 0;
}