#include <bits/stdc++.h>
using namespace std;

vector<int> v[501];
int n, cost[501], cnt[501], ans[501];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int m; 
        cin >> cost[i];
        ans[i] = cost[i];
        for(;;){
            cin >> m;
            if(m == -1) break;
            cnt[i]++;
            v[m].push_back(i);
        }
    }
}

void solve(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(cnt[i] == 0) q.push(i);

    while(!q.empty()){
        int f = q.front(); q.pop();
        for(auto k : v[f]){
            ans[k] = max(ans[k], ans[f] + cost[k]);
            if(--cnt[k] == 0) q.push(k);
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}