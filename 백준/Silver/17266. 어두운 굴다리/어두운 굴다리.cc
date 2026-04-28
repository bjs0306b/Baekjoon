#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    int arr[b]; for(int i=0;i<b;i++) cin >> arr[i];

    int mx = max(arr[0], a-arr[b-1]);
    for(int i=0;i<b-1;i++){
        if(arr[i+1]-arr[i] > 2*mx) mx = (arr[i+1]-arr[i]+1)/2;
    }
    cout << mx;
    
    return 0;
}