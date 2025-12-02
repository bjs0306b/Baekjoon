#include <bits/stdc++.h>
using namespace std;

long long ans1, ans2;

long long gcd(long long a, long long b){
    if(b == 0){
        ans1 = 1;
        ans2 = 0;
        return a;
    }
    long long ret = gcd(b, a%b);
    long long temp = ans1;
    ans1 = ans2;
    ans2 = temp + ans2 * (-1) * (a/b);
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long n, a; cin >> n >> a;
    cout << n-a << " ";

    if(gcd(n, a) == 1) cout << (ans2 % n + n) % n;
    else cout << -1;

    return 0;
}