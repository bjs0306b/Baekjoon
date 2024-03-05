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
    int n; cin >> n;
    while(n--){
        int arr[5]; for(int i=0;i<5;i++) cin >> arr[i];
        sort(arr,arr+5);
        if(arr[3]-arr[1] > 3) cout << "KIN\n";
        else cout << arr[1]+arr[2]+arr[3] << "\n";
    }
    
    return 0;
}