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
    int a,b; cin >> a >> b; int mx = INT32_MIN;
    int arr[a+1]; arr[0] = 0; for(int i=1;i<=a;i++){int num; cin >> num; arr[i] = arr[i-1]+num;}
    for(int i=0;i<a-b+1;i++) mx = max(mx, arr[i+b]-arr[i]);
    cout << mx;
    return 0;
}