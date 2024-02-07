#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >>arr[i];
    int cnt = 1, max = arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i] > max) {cnt++; max = arr[i];}
    }
    cout << cnt;
    
    return 0;
}