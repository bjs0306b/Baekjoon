#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, cnt=0;
    cin >> n;
    int num, arr[n-1]; cin >> num; for(int i=0;i<n-1;i++) cin >> arr[i];
    if(n==1) {cout << 0; return 0;}
    for(;;){
        auto iter = max_element(arr, arr+n-1);
        if(*iter < num) break;
        arr[iter-arr]--;
        num++; cnt++;
    }
    cout << cnt;
    
    return 0;
}