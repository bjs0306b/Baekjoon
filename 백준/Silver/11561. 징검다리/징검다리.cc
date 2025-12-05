#include <bits/stdc++.h>
using namespace std;

long long binary_search(long long n){
    long long s = 1, e = 150000000, m;
    long long ans;
    while(s <= e){
        m = (s+e)/2;

        long long temp = m*(m+1)/2;

        if(temp <= n){
            ans = m;
            s = m+1;
        }
        else e = m-1;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        cout << binary_search(n) << "\n";
    }

    return 0;
}