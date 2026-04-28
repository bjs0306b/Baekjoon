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
    while(n--){
        int m; cin >> m;
        int arr[m]; for(int i=0;i<m;i++) cin >> arr[i];
        int temp = 0;
        int mx = INT32_MIN;
        for(int i=0;i<m;i++){
            temp += arr[i];
            mx = max(temp, mx);
            if(temp<0) temp = 0;
        }
        cout << mx << "\n";
    }
    
    return 0;
}