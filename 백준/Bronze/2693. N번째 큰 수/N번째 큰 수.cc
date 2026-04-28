#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int arr[10]; for(int j=0;j<10;j++) cin >> arr[j];
        sort(arr, arr+10); 
        cout << arr[7] << "\n";
    }
    
    return 0;
}