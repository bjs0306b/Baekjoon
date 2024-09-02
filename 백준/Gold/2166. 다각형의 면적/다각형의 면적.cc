#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    double arr[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin >> arr[i][j];
        }
    }

    double temp = 0;
    for(int i=0;i<n;i++){
        if(i != n-1){
            temp += arr[i][0] * arr[i+1][1] - arr[i][1] * arr[i+1][0];
        }
        else temp += arr[i][0] * arr[0][1]- arr[i][1] * arr[0][0];
    }

    double ans = abs(temp)/2;

    printf("%.1f", ans);
    
    return 0;
}