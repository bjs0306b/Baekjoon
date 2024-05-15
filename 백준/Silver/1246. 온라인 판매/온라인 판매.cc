#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    int arr[b]; for(int i=0;i<b;i++) cin >> arr[i];
    sort(arr,arr+b);
    int mx = 0;
    int cnt = 0;
    for(int i=0;i<b;i++){
        if(mx<arr[i]*min(a,b-i)){
            mx = arr[i]*min(a,b-i);
            cnt = arr[i];
        }
    }
    cout << cnt << " "<< mx;
    
    return 0;
}