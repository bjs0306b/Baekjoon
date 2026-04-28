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
    int arr[4]; for(int i=0;i<4;i++)cin>>arr[i];
    sort(arr, arr+4);
    cout << arr[0]*arr[2]; 
    
    
    return 0;
}