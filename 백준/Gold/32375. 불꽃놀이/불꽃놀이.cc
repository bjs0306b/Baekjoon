#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    deque<int> dq(n); for(int i=0;i<n;i++) cin >> dq[i];
    sort(dq.begin(), dq.end());
    
    int ans = 0;

    while(!dq.empty()){
        int f = dq.front();
        dq.pop_front();
        if(f >= k)
            ans++;
        else{
            auto iter = lower_bound(dq.begin(), dq.end(), k-f);
            if(iter != dq.end()){
                ans++;
                dq.erase(iter);
            }
            else break;
        }
    }
    if(ans) cout << ans;
    else cout << -1;
    
    return 0;
}