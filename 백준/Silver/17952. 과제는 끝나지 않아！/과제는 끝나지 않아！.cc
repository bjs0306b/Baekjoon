#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    stack<pair<int,int>> s;
    while(n--){
        bool f; cin >> f;
        if(f){
            int a,t; cin >> a >> t;
            s.push({a,t});
        }
        if(!s.empty() && --s.top().second == 0){ans += s.top().first; s.pop();}
    }
    cout << ans;

    return 0;
}