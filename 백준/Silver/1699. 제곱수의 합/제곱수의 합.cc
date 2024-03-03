#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int dp[100001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for(int i=2;i*i<100000;i++){
        v.push_back(i*i);
    }
    for(int i=0;i<100001;i++) dp[i] = i;
    for(auto k : v){
        for(int i=0;i<100000-k;i++){
            dp[i+k] = min(dp[i+k], dp[i] + 1);
        }
    }
    cout << dp[n];
    
    return 0;
}