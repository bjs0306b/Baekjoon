#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) v[i]=i+1;
    int m; cin >> m;
    int ans = 0;
    while(m--){
        int num; cin >> num;
        auto iter = upper_bound(v.begin(), v.end(), num);
        if(iter == v.begin()) break;
        v.erase(iter-1);
        ans++;
    }
    cout << ans;
    return 0;
}