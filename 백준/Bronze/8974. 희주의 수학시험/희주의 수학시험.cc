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
    int arr[1500];
    arr[0] = 0;
    int temp = 1;
    for(int i=1;i<50;i++){
        for(int j=0;j<i;j++){
            arr[temp] = arr[temp-1] + i;
            temp++;
        }
    }
    int a,b; cin >> a >> b;
    cout << arr[b] - arr[a-1];
    
    return 0;
}

