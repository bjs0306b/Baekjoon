#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n-1;i++){
        dp[i][i+1] = abs(v[i+1] - v[i]);
    }

    for(int l=3;l<=n;l++){
        for(int s=0;s<n-l+1;s++){
            int e = s + l - 1;
            for(int m=s;m<s+l-1;m++){
                dp[s][e] =max(max(dp[s][e], dp[s][m] + dp[m+1][e]), abs(v[e] - v[s]));
            }
        }
    }
    cout << dp[0][n-1];

    return 0;
}