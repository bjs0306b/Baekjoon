#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n]; memset(arr, 0, n*4);

    for(int i=1;i<=n;i++){
        int num; cin >> num;

        for(int j=0;j<n;j++){
            if(num == 0 && arr[j] == 0){
                arr[j] = i; break;
            }
            if(arr[j] == 0) num--;
        }
    }
    
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
    
    return 0;
}