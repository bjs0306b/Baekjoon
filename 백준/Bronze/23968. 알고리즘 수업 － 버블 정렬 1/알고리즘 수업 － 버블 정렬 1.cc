#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,k; cin >> n >> k;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                k--;
                if(k==0){
                    cout << arr[j] << " " << arr[j+1];
                    return 0;
                }
            }
        }
    }
    cout << -1;
    
    return 0;
}