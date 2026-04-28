#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    long long arr[n+1];
    arr[1] = 1; arr[2] = 2;
    for(int i=3;i<n+1;i++){
        arr[i] = (arr[i-1]+arr[i-2])%15746;
    }
    cout << arr[n];
    
    return 0;
}