#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    long long arr[n+1]; for(int i=1;i<=n;i++) cin >> arr[i];

    sort(arr+1, arr+n+1);

    long long sum = 0;
    for(int i=1;i<=n;i++){
        sum += abs(arr[i] - i);
    }
    cout << sum;
    return 0;
}