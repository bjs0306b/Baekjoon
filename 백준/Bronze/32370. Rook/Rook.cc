#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;

    if(ax == 0){
        if(bx == 0){
            if(by < ay) cout << 3;
            else cout << 1;
        }
        else cout << 1;
    }
    else if(ay == 0){
        if(by == 0){
            if(bx < ax) cout << 3;
            else cout << 1;
        }
        else cout << 1;
    }
    else cout << 2;

    return 0;
}