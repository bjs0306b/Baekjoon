#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> arr[i][j];

    int ans = 0;
    for(int i=0;i<m-2;i++){
        for(int j=i+1;j<m-1;j++){
            for(int k=j+1;k<m;k++){
                int sum = 0;
                for(int l=0;l<n;l++){
                    sum += max(max(arr[l][i], arr[l][j]), arr[l][k]);
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans;

    return 0;
}