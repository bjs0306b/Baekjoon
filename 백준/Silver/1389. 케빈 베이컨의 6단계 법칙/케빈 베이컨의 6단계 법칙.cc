#include<bits/stdc++.h>
using namespace std;

int arr[101][101];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a>> b;
    for(int i=0;i<b;i++){
        int x,y; cin >> x >> y;
        arr[x][y] = arr[y][x] = 1;
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            for(int k=1;k<=a;k++){
                if(arr[j][i] && arr[i][k]) 
                {
                    if(arr[j][k] == 0) arr[j][k] = arr[j][i] + arr[i][k];
                    else arr[j][k] = min(arr[j][k] , arr[j][i] + arr[i][k]);
                }
            }
        }
    }
    int mn = 1e9;
    int idx =0;
    for(int i=1;i<=a;i++){
        int sum = 0;
        for(int j=1;j<=a;j++){
            sum += arr[i][j];
        }

        if(mn >sum){
            mn = sum;
            idx = i;
        }
    }
    cout << idx;
    

    
    return 0;
}