#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<int> v(n+1); for(int i=1;i<=n;i++) cin >> v[i]; v[0] = 0;
    vector<int> dif(n); for(int i=0;i<n;i++) dif[i] = v[i+1] - v[i];

    for(int i=0;i<m;i++){
        int a, b, c; cin >> a >> b >> c;
        dif[a-1] += c; 
        if(b != n) dif[b] -= c;
    }

    int temp = v[0];
    for(int i=0;i<n;i++){
        temp += dif[i];
        cout << temp << " ";
    }
    return 0;
}