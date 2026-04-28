#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v;
void input(){
    cin >> n;
    v.resize(n);
    for(long long i=0;i<n;i++) cin >> v[i];
}

void solve(){
    long long ans = 0, sum = 0;;
    long long mx = 0, cur_idx = n;
    for(long long i=n-1;i>=0;i--){
        if(v[i] > mx){
            ans += (cur_idx - i - 1) * mx - sum;
            cur_idx = i;
            sum = 0;
            mx = v[i];
        }
        else sum += v[i];
    }
    ans += cur_idx * mx - sum;
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long t; cin >> t;
    while(t--){
        input();
        solve();
    }
    
    return 0;
}