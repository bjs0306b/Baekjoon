#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;  
    int arr[5]; for(int i=0;i<5;i++) cin >> arr[i];
    cout << count(arr, arr+5, n);
    
    
    return 0;
}