#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    vector<int> sum(n); sum[0] = v[0]; for(int i=1;i<n;i++) sum[i] = sum[i-1] + v[i];

    int ans = 0;
 
    for(int i=1;i<n-1;i++){  // 벌 벌 꿀
        ans = max(ans, sum[n-1] - sum[0] + sum[n-1] - sum[i] - v[i]);
    }

    for(int i=1;i<n-1;i++){ // 꿀 벌 벌
        ans = max(ans, sum[n-2] + sum[i-1] - v[i]);
    }
    
    for(int i=1;i<n-1;i++){ // 벌 꿀 벌
        ans = max(ans, sum[i] - sum[0] + sum[n-2] - sum[i-1]);
    }

    cout << ans;

    return 0;
}