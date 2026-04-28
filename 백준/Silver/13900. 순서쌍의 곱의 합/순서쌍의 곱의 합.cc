#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    long long arr[n], sum[n];

    for(int i=0;i<n;i++) cin >> arr[i];

    sum[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        sum[i] = sum[i+1] + arr[i];
    }
    long long ans = 0;
    for(int i=0;i<n-1;i++){
        ans += arr[i]*sum[i+1];
    }
    cout << ans;
    
    return 0;
}