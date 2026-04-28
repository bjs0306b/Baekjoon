#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
map<int,int> m;

void input(){
    cin >> n;
    v.resize(n);
    vector<pair<int,int>> temp(n);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        m[b] = a;
        temp[i] = {a,b};
    }
    sort(temp.begin(), temp.end());
    for(int i=0;i<n;i++) v[i] = temp[i].second;
}

void solve(){
    vector<int> dp;
    vector<int> pos_v;
    for(int i=0;i<n;i++){
        auto iter = lower_bound(dp.begin(), dp.end(), v[i]);
        int pos = iter - dp.begin();
        pos_v.push_back(pos);
        if(iter == dp.end()){
            dp.push_back(v[i]);
        }
        else{
            *iter = v[i];
        }
    }

    vector<int> vv;
    int temp= dp.size() - 1;
    for(int i=n-1;i>=0;i--){
        if(pos_v[i] == temp){
            temp--;
        }
        else vv.push_back(m[v[i]]);
    }

    cout << n - dp.size() << "\n";

    for(int i=vv.size()-1;i>=0;i--){
        cout << vv[i] << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}