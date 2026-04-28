#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
}

void solve(){  
    sort(v.begin(), v.end());
    vector<int> pre_sum(n); pre_sum[0] = v[0];
    for(int i=1;i<n;i++) pre_sum[i] = pre_sum[i-1] + v[i];

    int mn = INT32_MAX;
    int ans = -1;
    for(int i=0;i<n;i++){
        int temp = (pre_sum[n-1] - pre_sum[i]) - pre_sum[i] + (2*i + 2 - n) * v[i];
        if(mn > temp){
            mn = temp;
            ans = v[i];
        }
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}