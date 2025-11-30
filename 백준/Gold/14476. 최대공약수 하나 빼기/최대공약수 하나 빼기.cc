#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a%b) return gcd(b, a%b);
    return b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];

    vector<int> f(n), b(n); // f[k]는 0~k 까지의 gcd, b[k]는 k~n-1 까지의 gcd
    f[0] = v[0], b[n-1] = v[n-1];
    for(int i=1;i<n;i++){
        f[i] = gcd(f[i-1], v[i]);
    }
    for(int i=n-2;i>=0;i--){
        b[i] = gcd(b[i+1], v[i]);
    }

    int ans = f[n-1], ans_idx = -1;
    for(int i=0;i<n;i++){
        if(i == 0){
            if(ans < b[1]){
                ans = b[1];
                ans_idx = i;
            }
        }
        else if(i == n-1){
            if(ans < f[n-2]){
                ans = f[n-2];
                ans_idx = i;
            }
        }
        else{
            int temp = gcd(f[i-1], b[i+1]);
            if(ans < temp){
                ans = temp;
                ans_idx = i;
            }
        }
    }

    if(ans_idx == -1) cout << -1;
    else cout << ans << " " << v[ans_idx];

    return 0;
}