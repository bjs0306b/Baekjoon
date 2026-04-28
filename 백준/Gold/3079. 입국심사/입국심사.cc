#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long a,b; cin >> a >> b;
    vector<long long> v(a); for(int i=0;i<a;i++) cin >> v[i];
    long long e = *max_element(v.begin(), v.end()) * b;
    long long s = 1;
    long long m;

    while(s<=e){
        m = (s+e)/2;
        long long cnt = 0;
        for(auto k : v){
            cnt += (m/k);
            if(cnt > b) break;
        }
        if(cnt >= b) e = m-1;
        else s = m+1;
    }
    cout << s;

    return 0;
}