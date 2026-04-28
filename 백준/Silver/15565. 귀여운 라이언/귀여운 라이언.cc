#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m; cin >> n >> m;
    vector<int> v;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(num == 1) v.push_back(i);
    }

    int mn = INT32_MAX;
    if(v.size() < m) {
        cout << -1;
        return 0;
    }
    for(int i=0;i<v.size()-m+1;i++){
        int num = v[i+m-1] - v[i];
        mn = min(mn, num);
    }
    cout << mn+1;

    return 0;
}