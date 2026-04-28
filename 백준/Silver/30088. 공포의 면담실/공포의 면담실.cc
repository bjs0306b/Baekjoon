#include <bits/stdc++.h>
using namespace std;

long long ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        int m; cin >> m;
        long long sum = 0;
        for(int j=0;j<m;j++){
            long long num; cin >> num;
            sum += num;
        }
        v[i] = sum;
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++){
        ans += (n-i) * v[i];
    }
    cout << ans;
    
    return 0;
}