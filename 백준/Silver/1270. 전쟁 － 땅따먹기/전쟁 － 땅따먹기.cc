#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long n; cin >> n;
    map<long long,long long> m;
    while(n--){
        long long t; cin >> t;
        m.clear();
        for(long long i=0;i<t;i++){
            long long num; cin >> num;
            m[num]++;
        }

        bool flag = false;
        for(auto k : m){
            if(k.second > t/2){
                cout << k.first << "\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << "SYJKGW\n";
    }

    return 0;
}