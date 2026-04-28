#include<bits/stdc++.h>
using namespace std;

vector<long long> v1,v2;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n; cin >> n;
    long long arr[n][4]; for(long long i=0;i<n;i++) for(long long j=0;j<4;j++) cin >> arr[i][j];


    
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            long long temp= arr[i][0] + arr[j][1];
            v1.push_back(temp);
        }
    }
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            long long temp= arr[i][2] + arr[j][3];
            v2.push_back(temp);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long ans = 0;
    for(auto k : v1){
        long long temp = upper_bound(v2.begin(), v2.end(), -k) - lower_bound(v2.begin(), v2.end(), -k);
        ans += temp;
    }   

    cout << ans;
    
    return 0;
}