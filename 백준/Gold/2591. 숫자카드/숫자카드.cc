#include <bits/stdc++.h>
using namespace std;

int dp[40];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    dp[0] = 1, dp[1] = 1;
    for(int i=2;i<=s.size();i++){
        if(s[i-1] != '0') dp[i] += dp[i-1];
        
        if(s[i-2] != '0'){
            int temp = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if(temp > 0 && temp < 35) dp[i] += dp[i-2];
        }

        if(dp[i] == 0){
            cout << 0; return 0;
        }
    }

    cout << dp[s.size()];

    return 0;
}