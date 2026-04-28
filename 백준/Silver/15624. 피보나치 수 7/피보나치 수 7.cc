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
    long long n; cin >> n;
    arr[1] = 1;
    arr[2] = 1;
    for(int i=3;i<=n;i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 1000000007;
    }
    cout << arr[n];
    return 0;
}