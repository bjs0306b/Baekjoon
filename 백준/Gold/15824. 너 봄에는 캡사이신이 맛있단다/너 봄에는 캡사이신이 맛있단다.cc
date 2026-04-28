#include <bits/stdc++.h>
using namespace std;

long long n, ans;
vector<long long> v, twos;

void input(){
    cin >> n;
    v.resize(n);
    twos.resize(n);
    twos[0] = 1;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if(i) twos[i] = (twos[i-1] * 2) % 1000000007;
    }
    sort(v.begin(), v.end());
}

void solve(){
    for(int i=0;i<n;i++){
        long long cnt = twos[i] - twos[n-1-i]; // v[i]가 최대일 때 - v[i]가 최소일 때
        long long temp = ((v[i] % 1000000007) * cnt) % 1000000007;
        ans = (ans + temp + 1000000007) % 1000000007;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}