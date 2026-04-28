#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int arr[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    cout << arr[i][k] << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}