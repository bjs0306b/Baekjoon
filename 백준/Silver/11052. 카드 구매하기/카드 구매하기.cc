#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int arr[1001], dp[1001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i+1];
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j] = max(dp[j], dp[j-i] + arr[i]);
        }
    }
    cout << dp[n];
    return 0;
}