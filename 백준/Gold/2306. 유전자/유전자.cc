#include <bits/stdc++.h>
using namespace std;

int dp[500][500];
int ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s; int size = s.size();

    for (int i = 0; i < size - 1; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 't' || s[i] == 'g' && s[i + 1] == 'c')
        {
            dp[i][i + 1] = 2;
            ans = 2;
        }
    }

    for (int len = 3; len <= size; len ++)
    {
        for (int i = 0; i < size - len + 1; i++)
        {
            int e = i + len - 1;
            if (s[i] == 'a' && s[e] == 't' || s[i] == 'g' && s[e] == 'c')
                dp[i][e] = max(dp[i][e], dp[i + 1][e - 1] + 2);
            for(int j=i;j<e;j++){
                dp[i][e] = max(dp[i][e], dp[i][j] + dp[j+1][e]);
            }
        }
    }

    cout << dp[0][size-1];
    

    return 0;
}