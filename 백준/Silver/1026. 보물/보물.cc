#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, sum = 0;
    cin >> n;
    int arr1[n], arr2[n];
    for(int i=0;i<n;i++)  cin >> arr1[i];
    for(int i=0;i<n;i++)  cin >> arr2[i];
    sort(arr1, arr1+n);
    sort(arr2, arr2+n, greater<int>());
    for(int i=0;i<n;i++){
        sum+= arr1[i]*arr2[i];
    }
    cout << sum;
    return 0;
}