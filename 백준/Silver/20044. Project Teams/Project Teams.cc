#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[2*n]; for(int i=0;i<2*n;i++) cin >> arr[i];

    sort(arr, arr+2*n);

    int mn = INT32_MAX;
    for(int i=0;i<n;i++){
        mn = min(mn, arr[i]+arr[2*n-i-1]);
    }
    cout << mn;
    return 0;
}