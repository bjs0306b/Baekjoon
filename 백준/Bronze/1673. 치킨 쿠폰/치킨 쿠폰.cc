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
    int a,b;
    while(cin >> a >> b){
        int ans = a;
        int coupon = a;
        for(;;){
            ans += coupon/b;
            coupon = coupon%b + coupon/b;
            if(coupon < b) break;
        }
        cout << ans << "\n";
    }
    return 0;
}