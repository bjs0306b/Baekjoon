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
    int arr[n], dp[n]; for(int i=0;i<n;i++){cin >> arr[i]; dp[i] = 1;}
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
    }
    cout << *max_element(dp, dp+n);
    
    return 0;
}