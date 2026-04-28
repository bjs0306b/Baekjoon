#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    int ans; cin >> ans;
    sort(arr, arr+n);
    for(int i=0;i<n-1;i++){
        int num = ans - arr[i];
        if(binary_search(arr+i+1, arr+n, num)) cnt++;
    }
    cout << cnt;
    return 0;
}