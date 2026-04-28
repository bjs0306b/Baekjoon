#include <bits/stdc++.h>
using namespace std;

int n,x;
vector<int> v, pre_sum;
void input(){
    cin >> n >> x;
    v.resize(n);
    pre_sum.resize(n+1);
    for(int i=0;i<n;i++){
        cin >> v[i];
        pre_sum[i+1] = pre_sum[i] + v[i];
    }
}

void solve(){
    int cnt = 0, mx = 0;
    for(int i=x;i<=n;i++){
        if(mx < pre_sum[i] - pre_sum[i-x]){
            mx = pre_sum[i] - pre_sum[i-x];
            cnt = 0;
        }
        if(mx == pre_sum[i] - pre_sum[i-x]) cnt++;
    }
    if(mx == 0) cout << "SAD";
    else cout << mx << "\n" << cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}