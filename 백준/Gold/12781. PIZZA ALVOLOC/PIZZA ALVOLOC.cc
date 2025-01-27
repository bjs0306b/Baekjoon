#include <bits/stdc++.h>
using namespace std;

struct dot{
    int x,y;
};

dot d[4];

long long ccw(int a, int b, int c){
    int x1 = d[b].x - d[a].x, y1 = d[b].y - d[a].y, x2 = d[c].x - d[a].x, y2 = d[c].y - d[a].y;
    return x1*y2 - x2*y1;
}

int main()  
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<4;i++) cin >> d[i].x >> d[i].y;

    if(ccw(0,1,2)*ccw(0,1,3) < 0) cout << 1;
    else cout << 0;
    
    
    return 0;
}