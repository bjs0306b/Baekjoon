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
    int arr[3]; for(int i=0;i<3;i++) cin >> arr[i];
    sort(arr, arr+3);
    string s; cin >> s;
    for(auto k : s){
        int num = k - 'A';
        cout << arr[num] << ' ';
    }
    
    
    return 0;
}