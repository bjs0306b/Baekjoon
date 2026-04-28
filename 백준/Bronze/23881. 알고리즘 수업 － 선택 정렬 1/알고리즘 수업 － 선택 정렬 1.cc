#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m; cin >> n >> m;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    int cnt = 0;
    for(int i=n-1;i>=1;i--){
        auto iter = max_element(arr, arr+i+1);
        int pos = iter - arr;
        if(pos != i){
            cnt++;
            if(cnt == m){
                cout << arr[i] << " " << arr[pos] << "\n";
                return 0;
            }
            swap(arr[pos], arr[i]);
        }
    }
    cout << -1;
    
    return 0;
}