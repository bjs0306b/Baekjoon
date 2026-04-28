#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    vector<int> dp;

    for(int i=0;i<n;i++){
        auto iter = lower_bound(dp.begin(), dp.end(), v[i]);
        if(iter == dp.end()) dp.push_back(v[i]);
        else *iter = v[i];
    }
    cout << n - dp.size();

    return 0;
}