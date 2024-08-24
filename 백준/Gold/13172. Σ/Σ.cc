#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> m;

#define X 1000000007

long long power(long long a, long long b){
    long long ret = 1;
    while(b){
        if(b%2) ret = (ret * a) % X;
        a = (a * a) % X;
        b/=2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        m[a]+=b;
    }

    long long ans = 0;
    for(auto k : m){
        ans += (k.second * power(k.first, X-2)) % X;
        ans %= X;
    }
    cout << ans;
    
    
    return 0;
}