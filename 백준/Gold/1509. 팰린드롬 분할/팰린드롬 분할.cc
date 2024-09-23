#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int size = s.size();
    
    vector<int> vec[size];
    int dp[size][2]; for(int i=0;i<size;i++) for(int j=0;j<2;j++) dp[i][j] = INT32_MAX;
    for(int i=0;i<size;i++){ // odd
        int temp = 1;
        for(;;){
            if(i-temp < 0 || i+temp >= size || s[i-temp] != s[i+temp]) break;
            vec[i-temp].push_back(2*temp);
            temp++;
        }
    }

    for(int i=0;i<size-1;i++){ // even
        int temp = 0;
        for(;;){
            if(i-temp < 0 || i+1+temp >= size || s[i-temp] != s[i+1+temp]) break;
            vec[i-temp].push_back(1+temp*2);
            temp++;
        }
    }   

    // for(int i=0;i<size;i++){
    //     for(auto k : vec[i]) cout << k << " ";
    //     cout << "\n";
    // }

    dp[0][0] = 1;
    for(int i=0;i<size-1;i++){
        for(auto k : vec[i]){
            if(i+k < size) dp[i+k][1] = min(dp[i+k][1], dp[i][0]);
        }
        dp[i+1][0] = min(min(dp[i][0], dp[i][1])+1, dp[i+1][0]);
    }
    cout << min(dp[size-1][0],dp[size-1][1]);

    return 0;
}