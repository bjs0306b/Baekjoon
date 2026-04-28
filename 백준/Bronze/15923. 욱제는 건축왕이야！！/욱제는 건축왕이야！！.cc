#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        v[i] = {a,b};
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int dis = abs(v[(i+1)%n].first - v[i].first) + abs(v[(i+1)%n].second - v[i].second);
        ans += dis;
    }
    cout << ans;

    return 0;
}