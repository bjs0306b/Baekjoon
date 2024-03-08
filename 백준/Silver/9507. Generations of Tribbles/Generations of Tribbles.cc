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
    long long arr[68];
    arr[0] = 1; arr[1] = 1; arr[2] = 2; arr[3] = 4;
    for(int i=4;i<69;i++) arr[i] = arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    while(n--){
        int num; cin >> num;
        cout << arr[num] << "\n";
    }
    
    return 0;
}