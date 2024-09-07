#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n); for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> dp;

    for(int i=0;i<n;i++){
        auto iter = lower_bound(dp.begin(), dp.end(), arr[i]);

        if(iter == dp.end()) dp.push_back(arr[i]);
        else *iter = arr[i];
    }

    cout << dp.size();

    
    return 0;
}