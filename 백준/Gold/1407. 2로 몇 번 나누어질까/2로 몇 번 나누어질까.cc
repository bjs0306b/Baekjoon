#include <bits/stdc++.h>
using namespace std;

long long func(long long n){
    long long ret = 0;
    long long i = 2;
    vector<long long> v;
    for(;i<=n;i*=2){
        v.push_back(n/i);
    }
    v.push_back(0);
    i /= 2;
    for(int j = v.size()-2; j>=0; j--){
        ret += (v[j] - v[j+1]) * i;
        i /= 2;
    }
    ret += (n - v[0]);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m; cin >> n >> m;
    cout << func(m) - func(n-1);

    return 0;
}