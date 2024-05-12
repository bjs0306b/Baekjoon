#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        bool flag = 1;
        for(int j=0;j<n;j++){
             if(i==j) continue;

             if(v[i].first >= v[j].first && v[i].second >= v[j].second){
                 flag = 0;
                 break;
             }
        }
        if(flag) ans++;
    }

    cout << ans;
    return 0;
}