#include<bits/stdc++.h>
using namespace std;

bool arr[1001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    arr[1] = 1, arr[2] = 0, arr[3] = 1, arr[4] = 1;

    if(n < 5){
        if(arr[n]) cout << "SK";
        else cout << "CY";
        return 0;
    }

    for(int i=5;i<=n;i++){
        if(arr[i-1] && arr[i-3] && arr[i-4]) arr[i] = 0;
        else arr[i] = 1;
    }

    if(arr[n]) cout << "SK";
    else cout << "CY";
    
    
    return 0;
}