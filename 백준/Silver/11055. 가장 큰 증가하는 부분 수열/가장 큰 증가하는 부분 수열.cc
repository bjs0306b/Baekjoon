#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n], dp[n]; for(int i=0;i<n;i++){int num; cin >> num; arr[i] = num; dp[i] = num;}
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] < arr[j]){
                dp[j] = max(dp[j], arr[j]+dp[i]);
            }
        }
    }
    cout << *max_element(dp,dp+n);
    
    return 0;
}