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

    int left = 0, right = 0;
    int left_max = 0, right_max = 0;
    for(int i=0;i<n;i++){
        if(left_max < arr[i]){
            left_max = arr[i];
            left++;
        }
    }
    for(int i = n-1;i >= 0; i--){
        if(right_max < arr[i]){
            right_max = arr[i];
            right++;
        }
    }
    cout << left << "\n" << right;
    
    return 0;
}