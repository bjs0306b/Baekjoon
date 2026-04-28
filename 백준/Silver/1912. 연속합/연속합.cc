#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[n], dp[n];
    for(int i=0;i<n;i++){int num; cin >> num; arr[i]=num; dp[i]=num;}
    for(int i=1;i<n;i++){
        dp[i] = max(dp[i], arr[i]+dp[i-1]);
    }
    cout << *max_element(dp, dp+n);
    
    return 0;
}