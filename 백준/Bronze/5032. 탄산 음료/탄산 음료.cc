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
    int a,b,c; cin >> a >> b >> c;
    int ans = 0;
    a += b;
    for(;;){
        int ex = a / c;
        ans += ex;
        a = a - a/c*c + ex;
        if(a<c) break;
    }
    cout << ans;
}