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
    int arr[n]; for(int i=0;i<n;i++)cin>>arr[i];
    if(prev_permutation(arr, arr+n))
        for(int i=0;i<n;i++)cout << arr[i] << " ";
    else cout << -1;
    return 0;
}