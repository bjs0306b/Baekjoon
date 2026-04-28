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
    vector<bool> v;
    while(n){
        v.push_back(n%2);
        n /= 2;
    }
    int ans = 0;
    int mul = 1;
    while(!v.empty()){
        ans += v.back() * mul;
        mul *= 2;
        v.pop_back();
    }
    cout << ans;
    return 0;
}
