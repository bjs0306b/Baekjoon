#include <bits/stdc++.h>
using namespace std;

long long c,k,p;
void input(){
    cin >> c >> k >> p;
}

void solve(){
    long long ans = 0;
    for(int i=1;i<=c;i++){
        long long temp = k*i + p*i*i;
        ans += temp;
    }
    cout << ans;    
}

int main(){
    cin.tie(0)->sync_with_stdio(0); 

    input();
    solve();

    return 0;
}