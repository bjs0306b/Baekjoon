#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int l = 0, r = v[n-1];
    int ans;
    while(l<=r){
        int m = (l+r)/2;
        int cnt = 1;
        int s = v[0];
        for(int i=1;i<n;i++){
            if(v[i] - s >= m){
                s = v[i];
                cnt++;
            }
        }
        if(cnt >= c){
            l = m+1;
            ans = m;
        }
        else r = m-1;
    }
    cout << ans;

    return 0;
}