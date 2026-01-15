#include <bits/stdc++.h>
using namespace std;

long long n, ans;
vector<long long> v;
void input(){
    cin >> n;
    for(long long i=0;i<n;i++){
        long long num; cin >> num;
        ans += num;
        if(num) v.push_back(i);
    }
}

long long solve(){
    if(ans == 0) return n/2;
    for(long long i=0;i<v.size();i++){
        if(i == v.size()-1) ans += (n - v[i] + v[0])/2;
        else ans += (v[i+1] - v[i])/2;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}