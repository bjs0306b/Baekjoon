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
    int arr[n]; for(int i=0;i<n;i++){int num; cin >> num; arr[i] = num*(i+1);}
    cout << arr[0] << " ";
    for(int i=1;i<n;i++) cout << arr[i] - arr[i-1] << " ";

    
    return 0;
}

