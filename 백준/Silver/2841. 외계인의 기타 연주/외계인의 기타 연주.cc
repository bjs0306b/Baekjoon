#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    
    long long ans = 0;
    stack<int> st[7];
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        while(!st[a].empty() && st[a].top() > b){
            ans++;
            st[a].pop();
        }
        if(st[a].empty() || st[a].top() != b){st[a].push(b); ans++;}
    }
    cout << ans;

    return 0;
}