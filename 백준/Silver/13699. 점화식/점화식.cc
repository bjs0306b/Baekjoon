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
long long arr[36];


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    arr[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            arr[i] += arr[j]*arr[i-j-1];
        }
    }
    cout << arr[n];
    
    return 0;
}