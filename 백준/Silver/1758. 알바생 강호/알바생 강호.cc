#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n, greater<int>());
    long long sum = 0;
    for(int i=0;i<n;i++){
        long long tip = arr[i] - i;
        if(tip > 0) sum += tip;
    }
    cout << sum;
    
    return 0;
}