#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr,arr+n);
    int cnt = 1;
    for(int i=0;i<n;i++){
        if(arr[i] == cnt) cnt++;
        else{cout << cnt; return 0;}
    }
    cout << cnt;
    return 0;
} 