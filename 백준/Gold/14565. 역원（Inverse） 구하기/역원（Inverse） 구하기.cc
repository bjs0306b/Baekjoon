#include <bits/stdc++.h>
using namespace std;

long long n,a;

vector<long long> v;

long long gcd(long long aa, long long bb){
    if(aa % bb){
        v.push_back(aa/bb);
        return gcd(bb, aa%bb);
    }
    return bb;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> a;

    cout << n-a << " ";

    long long ans1, ans2;
    if(gcd(n,a) == 1){
        if(v.size() == 0){
            cout << 1;
            return 0;
        }
        ans1 = 1, ans2 = -1*v[v.size()-1];
        if(v.size() > 1){
            for(int i=v.size()-2;i>=0;i--){
                long long temp = ans1;
                ans1 = ans2;
                ans2 = temp + ans2*(-1)*v[i];
            }
        }
        cout << (ans2%n + n) % n;
    }
    else cout << -1;

    return 0;
}