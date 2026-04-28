#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n; long long arr[n+1];
    arr[1] = 1; arr[2] = 1;
    for(int i=3;i<n+1;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    cout << arr[n];
    
    
    return 0;
}