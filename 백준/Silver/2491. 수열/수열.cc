#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, mx = 1; cin >> n; int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n-1;i++){
        int temp = 1;
        if(arr[i] <= arr[i+1]){
            while(arr[i] <= arr[i+1] && i<n-1){i++; temp++;}
        } 
        mx = max(temp, mx);
    }
    for(int i=0;i<n-1;i++){
        int temp = 1;
        if(arr[i] >= arr[i+1]){
            while(arr[i] >= arr[i+1] && i<n-1){i++; temp++;}
        } 
        mx = max(temp, mx);
    }
    cout << mx;
    
    
    return 0;
}