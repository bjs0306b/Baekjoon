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

long long arr[1000001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    arr[1] = 1;
    arr[0] = 1;
    arr[2] = 2;
    for(int i=3;i<1000001;i++){
        arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % 1000000009;
    }
    while(n--){
        int a; cin >> a;
        cout << arr[a] << "\n";
    }

    
    return 0;
}