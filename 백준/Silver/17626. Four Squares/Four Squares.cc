#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int dp[50001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<50001;i++) dp[i]=i;
    vector<int> v; for(int i=2;i*i<50000;i++) v.push_back(i*i);
    for(auto k : v){
        for(int i=0;i<50001-k;i++){
            dp[i+k] = min(dp[i]+1, dp[i+k]);
        }
    }
    cout << dp[n];
    
    return 0;
}