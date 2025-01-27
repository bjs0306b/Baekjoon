#include <iostream>
using namespace std;
 
typedef struct {
    int x, y;
}pii;
 
int ccw(pii a, pii b, pii c) {
    int ans = (b.x - a.x) * (c.y - a.y) - (b.y - a.y)* (c.x - a.x);
    if (ans < 0) return 1;
    else if (ans > 0) return -1;
    else return 0;
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    pii a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    
    int ans = ccw(a, b, c) * ccw(a, b, d);
    if (ans < 0) cout << "1";
    else cout << "0";
 
    return 0;
}