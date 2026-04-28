#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<int> v(m); for(int i=0;i<m;i++) cin >> v[i];

    int s = 1, e = *max_element(v.begin(), v.end());

    while(s <= e){
        int mid = (s+e)/2;

        int cnt = 0;
        for(auto k : v) cnt += (k + mid - 1) / mid;

        if(cnt > n) s = mid+1;
        else e = mid-1;
    }
    cout << s;

    return 0;
}