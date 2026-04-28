#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    int arr2[n]; for(int i=0;i<n;i++) arr2[i] = arr[i]*(n-i);
    cout << *max_element(arr2, arr2+n);
    return 0;
}