#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,d; cin >> n >> d;
    char arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    int cnt =0;
    for(int i=0;i<n;i++){
        if(arr[i] == 'P'){
            for(int j=i-d;j<=i+d;j++){
                if(j<0 || j>=n) continue;
                if(arr[j] == 'H'){
                    cnt++;
                    arr[j] = 'X';
                    break;
                }
            }
        }
    }
    cout << cnt;
    
    return 0;
}