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
int W, H, x, y, P;

bool dis(int a, int b){
    bool flag1 = pow((x - a),2) + pow((y + H/2 - b),2) <= pow(H/2,2);
    bool flag2 = pow((x + W - a),2) + pow((y + H/2 - b),2) <= pow(H/2,2);
    if(flag1 || flag2) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> W >> H >> x >> y >> P;
    int ans = 0 ;
    while(P--){
        int a,b; cin >> a >> b;
        if((a >= x && a <= x+W && b >= y && b <= y+H) || dis(a,b)) ans++;
    }
    cout << ans;
    
    
    return 0;
}