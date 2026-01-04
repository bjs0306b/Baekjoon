#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> a,b;

void input(){
    cin >> n >> m >> k;
    a.resize(m); for(int i=0;i<m;i++) cin >> a[i];
    b.resize(k); for(int i=0;i<k;i++) cin >> b[i];
}

void solve(){
    sort(a.begin(), a.end());
    vector<bool> visited(m, false);

    for(int i=0;i<k;i++){
        auto iter = upper_bound(a.begin(), a.end(), b[i]);
        while(visited[iter - a.begin()]) iter++;
        visited[iter - a.begin()] = true;
        cout << *iter << "\n";        
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    solve();
    return 0;
}