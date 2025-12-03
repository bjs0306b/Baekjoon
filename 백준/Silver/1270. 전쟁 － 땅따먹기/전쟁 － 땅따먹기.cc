#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        vector<long long> v(n); for(auto &k : v) cin >> k;
        long long num = -1, cnt = 0;
        for(long long i=0;i<n;i++){   
            if(cnt == 0){
                num = v[i];
                cnt++;
            }
            else if(num != v[i]){
                cnt--;
            }
            else{
                cnt++;
            }
        }   
        cnt = 0;
        for(long long i=0;i<n;i++){
            if(num == v[i]) cnt++;
        }
        if(cnt > n/2) cout << num << "\n";
        else cout << "SYJKGW\n";
    }

    return 0;
}