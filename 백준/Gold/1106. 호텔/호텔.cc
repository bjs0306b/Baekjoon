#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c,n;
    cin >> c >> n;

    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        for(int i=a;i<100001;i++){
            dp[i] = max(dp[i], dp[i-a] + b);
        }
    }
    for(int i=0;i<100001;i++){
        if(dp[i] >= c){
            cout << i; return 0;
        }
    }
    
    return 0;
}