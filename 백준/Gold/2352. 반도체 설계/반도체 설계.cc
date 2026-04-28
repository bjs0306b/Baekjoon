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
    vector<int> dp;
    for(int i=0;i<n;i++){
        auto iter = lower_bound(dp.begin(), dp.end(), v[i]);
        if(iter == dp.end()) dp.push_back(v[i]);
        else *iter = v[i];
    }
    cout << dp.size();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}