#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int arr[4]; for(int i=0;i<4;i++) cin >>arr[i]; sort(arr,arr+4);
    int ans = arr[0]+arr[3]-arr[2]-arr[1];
    if(ans < 0) cout << -1*ans;
    else cout << ans;
    
    
    return 0;
}