#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[4];
    int aa,bb; cin >>aa>>bb;
    arr[0] = bb;
    for(int i=1;i<4;i++){
        int a,b; cin >> a>>b;
        arr[i] = arr[i-1] -a+b;
    }
    cout << *max_element(arr, arr+4);
    
    
    return 0;
}