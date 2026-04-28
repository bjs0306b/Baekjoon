#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, sum = 0;
    cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=n-1;i>0;i--){
        if(arr[i] <= arr[i-1]){
            sum += (arr[i-1]-arr[i]+1);
            arr[i-1] = arr[i]-1;
        }
    }
    cout << sum;
    return 0;
}