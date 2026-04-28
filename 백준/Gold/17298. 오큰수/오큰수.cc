#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    int ans[n];
    stack<int> s;

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && v[i] >= s.top()) s.pop();
        if(s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }

    for(int i=0;i<n;i++) cout << ans[i] << " ";


    return 0;
}