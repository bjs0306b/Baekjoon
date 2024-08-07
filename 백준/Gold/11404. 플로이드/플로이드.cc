#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = 10000000;
        }
    }
    int m; cin >> m;
    while(m--){
        int a,b,c; cin >> a >> b >> c; 
        if(arr[a-1][b-1] > c) arr[a-1][b-1] = c;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 10000000) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}