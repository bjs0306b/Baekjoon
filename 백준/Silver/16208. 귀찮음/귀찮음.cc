#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    long long arr[n], sum = 0, ans = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+n);

    for(int i=0;i<n-1;i++){
        sum -= arr[i];
        ans += arr[i] * sum;
    }
    cout << ans;
    
    return 0;
}