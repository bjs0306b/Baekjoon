#include <bits/stdc++.h>
using namespace std;

map<long long,long long, greater<long long>> m;
long long sum;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long mx = 0;
    long long n,d; cin >> n >> d;
    for(long long i=0;i<n;i++){
        long long num; cin >> num;
        m[num]++;
        mx = max(mx, num);
    }
    d = min(mx, d);

    for(auto k : m){
        if(k.first < mx - d + 1) break;
        sum += (k.first - (mx - d)) * k.second;
    }
    cout << sum;



    return 0;
}