#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());

    int mn = INT32_MAX;
    pair<int,int> ans;

    for(int i=0;i<n-1;i++){
        auto iter = upper_bound(v.begin()+i+1, v.end(), -1*v[i]);
        int pos = iter - v.begin();
        
        if(pos == i+1){
            if(mn > abs(v[i] + v[pos])){
                mn = abs(v[i] + v[pos]);
                ans = {v[i], v[pos]};
            }
        }
        else if(pos == n){
            if(mn > abs(v[i] + v[pos-1])){
                mn = abs(v[i] + v[pos-1]);
                ans = {v[i], v[pos-1]};
            }
        }
        else{
            if(mn > abs(v[i] + v[pos])){
                mn = abs(v[i] + v[pos]);
                ans = {v[i], v[pos]};
            }
            if(mn > abs(v[i] + v[pos-1])){
                mn = abs(v[i] + v[pos-1]);
                ans = {v[i], v[pos-1]};
            }
        }
    }
    cout << ans.first << " " << ans.second;
    
    return 0;
}