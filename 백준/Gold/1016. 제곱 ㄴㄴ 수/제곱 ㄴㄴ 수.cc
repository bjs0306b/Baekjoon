#include <bits/stdc++.h>
using namespace std;

long long a,b;
vector<bool> is_prime, is_divisable;
vector<long long> primeXprime;
void input(){
    cin >> a >> b;
    is_prime.resize(1100000, true);
    is_prime[1] = false;
    for(long long i=2;i*i<=b;i++){
        if(!is_prime[i]) continue;
        primeXprime.push_back(i*i);
        for(long long j=i*2;j*j<=b;j+=i) is_prime[j] = false;
    }
}

void solve(){
    is_divisable.resize(b - a + 1);
    for(auto k : primeXprime){
        for(long long s = (k - a % k) % k; s <= b - a; s += k){
            is_divisable[s] = true;
        }
    }

    long long ans = 0;
    for(long long i=0;i<=b-a;i++){
        if(!is_divisable[i]) ans++;
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}