#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,l;
    cin >> n >> l;
    vector<long long> v(n); for(long long i=0;i<n;i++) cin >> v[i];
    long long e = *max_element(v.begin(), v.end());

    long long s = 1;

    while(s <= e){
        long long m = (s+e)/2;

        long long cnt = 0;
        for(auto k : v){
            cnt += k / m;
        }

        if(cnt >= l) s = m+1;
        else if(cnt < l) e = m-1;
    }
    cout << e;

    return 0;
}