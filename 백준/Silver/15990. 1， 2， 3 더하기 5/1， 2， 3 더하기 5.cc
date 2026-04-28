#include<bits/stdc++.h>
using namespace std;

long long arr[100004][4];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][3] = 1;
    
    for(int i=1;i<100001;i++){
        arr[i+1][1] = (arr[i+1][1] + arr[i][2] + arr[i][3])%1000000009;
        arr[i+2][2] = (arr[i+2][2] + arr[i][1] + arr[i][3])%1000000009;
        arr[i+3][3] = (arr[i+3][3] + arr[i][1] + arr[i][2])%1000000009;
    }
    
    for(int i=0;i<n;i++){
        int num; cin >> num;

        long long ans = 0;
        for(int j=1;j<=3;j++){
            ans += arr[num][j];
        }

        cout << ans%1000000009 << "\n";
    }

    return 0;
}