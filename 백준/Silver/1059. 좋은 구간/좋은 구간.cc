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
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];
    int num; cin >> num;
    sort(arr,arr+n);
    int start = 0, end = arr[n-1];
    for(int i=0;i<n;i++){
        if(arr[i] == num){cout << 0; return 0;}
        else if(arr[i] > num){
            if(i != 0) start = arr[i-1];
            end = arr[i];
            break;
        }
    }
    int cnt = 0;
    for(int i=start+1;i<=num;i++){
        for(int j = num; j < end; j++){
            cnt++;
        }
    }
    cout << cnt-1;
    return 0;
}