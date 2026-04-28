#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n; long long arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    if(!(arr[2]-arr[1] == arr[1]-arr[0])) cout << arr[n-1]/arr[n-2]*arr[n-1];
    else cout  << arr[n-1]*2-arr[n-2];
    
    return 0;
}   