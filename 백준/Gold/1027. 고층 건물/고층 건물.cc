#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> v(n); for(long long i=0;i<n;i++) cin >> v[i];

    long long ans = 0;
    for(long long i=0;i<n;i++){
        long long cnt = 0;
        for(long long j=0;j<n;j++){
            if(i < j){
                bool flag = true;
                for(long long k = i+1; k < j; k++){
                    if((v[j]-v[i])*(k-i) + v[i]*(j-i) <= v[k]*(j-i)){
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
            else if(i > j){
                bool flag = true;
                for(long long k = j+1; k < i; k++){
                    if((v[i]-v[j])*(k-j) + v[j]*(i-j) <= v[k]*(i-j)){
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
        }
            ans = max(ans, cnt);
        }
    cout << ans;

    return 0;
}