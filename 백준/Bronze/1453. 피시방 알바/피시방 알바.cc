#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,cnt=0, arr[101]; memset(arr, 0, 404);
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(arr[num]) cnt++;
        else arr[num] = 1;
    }
    cout << cnt;
    return 0;
}