#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if(a % b == 0) return b;
    return gcd(b, a%b);
}

long long C(int a, int b){
    if(a < 2*b) b = a-b;
    if(b == 0) return 1;
    vector<int> v(b);
    for(int i=0;i<b;i++) v[i] = a - i;
    for(int i=1;i<=b;i++){
        int temp = i;
        for(int j=0;j<b;j++){
            int temp2 = gcd(v[j], temp);
            if(temp2 > 1){
                v[j] /= temp2;
                temp /= temp2;
            }
            if(temp == 1) break;
        }
    }
    long long ret = 1;
    for(int i=0;i<b;i++) ret = (ret * v[i]);
    //cout << "a: " << a << ", b: " << b << ",ret : " << ret  << "\n";
    return ret;
}

int n;
void input(){
    cin >> n;
}

void solve(){
    long long ans = 0;
    for(int i=1;i<=n/4;i++){
        long long temp = C(13,i) * C(52-4*i, n-4*i);
        if(i % 2) ans += temp;
        else ans -= temp;
    }
    cout << ans % 10007;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}