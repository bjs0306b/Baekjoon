#include <bits/stdc++.h>
using namespace std;

map<int,int> r_cnt, c_cnt;


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        r_cnt[a]++, c_cnt[b]++;
    }

    int ans = 0;

    for(auto k : r_cnt){
        if(k.second > 1) ans++;
    }
    for(auto k : c_cnt){
        if(k.second > 1) ans++;
    }

    cout << ans;

    return 0;
}