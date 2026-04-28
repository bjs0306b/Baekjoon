#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> v[300001];
vector<pair<long long,long long>> e;
void input(){
    cin >> n;
    for(long long i=0;i<n-1;i++){
        long long a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        e.push_back({a,b});
    }
}

long long cnt_d(){
    long long ret = 0;
    for(long long i=0;i<n-1;i++){
        long long a = e[i].first, b = e[i].second;
        long long size1 = v[a].size(), size2 = v[b].size();
        ret += (size1-1)*(size2-1);
    }
    return ret;
}

long long cnt_g(){
    long long ret = 0;
    for(long long i=1;i<=n;i++){
        long long size = v[i].size();
        ret += (size * (size-1) *(size-2) / 6);
    }

    return ret;
}

void solve(){   
    long long d = cnt_d();
    long long g = cnt_g();
    if(d == 3*g) cout << "DUDUDUNGA";
    else if(d > 3*g) cout << "D";
    else cout << "G";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}