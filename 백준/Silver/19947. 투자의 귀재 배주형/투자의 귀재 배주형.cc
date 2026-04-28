#include<bits/stdc++.h>
using namespace std;
int arr[16];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a; int b; cin >> a >> b;
    
    arr[0] = a;

    for(int i=0;i<=10;i++){
        arr[i+1] = max(arr[i+1], int(arr[i]*1.05));
        arr[i+3] = max(arr[i+3], int(arr[i]*1.2));
        arr[i+5] = max(arr[i+5], int(arr[i]*1.35));
    }
    cout << arr[b];
    return 0;
}