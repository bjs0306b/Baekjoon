#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y; cin >> x >> y;
    int n; cin >> n;
    vector<pair<int,int>> v(n); for(int i=0;i<n;i++){int a,b; cin >> a >> b; v[i] = {a,b};}

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a = v[i].first, b = v[i].second, c = v[j].first, d = v[j].second;
            if((max(b+d, max(a,c)) <= max(x,y) && min(b+d, max(a,c)) <= min(x,y)) ||
            (max(a+c, max(b,d)) <= max(x,y) && min(a+c, max(b,d)) <= min(x,y)) ||
            (max(a+d, max(b,c)) <= max(x,y) && min(a+d, max(b,c)) <= min(x,y)) ||
            (max(b+c, max(a,d)) <= max(x,y) && min(b+c, max(a,d)) <= min(x,y)) )
                ans = max(ans, a*b + c*d);
        }
    }
    cout << ans;

    return 0;
}