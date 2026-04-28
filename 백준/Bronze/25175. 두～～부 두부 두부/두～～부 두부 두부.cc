#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long n,m,k; cin >> n >> m >> k;

    long long ans = (k%n - 3 + m + 100000 * n) % n;
    if(ans) cout << ans;
    else cout << n;

    return 0;
}