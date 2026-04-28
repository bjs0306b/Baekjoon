#include <bits/stdc++.h>
using namespace std;

struct node{
    int x1,y1,x2,y2;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    node a,b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    // (e) NULL
    if(a.y1 > b.y2 || b.y1 > a.y2 || a.x2 < b.x1 || b.x2 < a.x1) cout << "NULL";
    // (a) POINT
    else if(
        make_pair(a.x1, a.y1) == make_pair(b.x2, b.y2) || 
        make_pair(a.x2, a.y1) == make_pair(b.x1, b.y2) || 
        make_pair(a.x2, a.y2) == make_pair(b.x1, b.y1) || 
        make_pair(a.x1, a.y2) == make_pair(b.x2, b.y1)
    ) cout << "POINT";
    // (b) LINE
    else if(
        (a.x2 == b.x1 || b.x2 == a.x1) && (a.y1 < b.y2 && a.y2 > b.y1) ||
        (a.y2 == b.y1 || b.y2 == a.y1) && (a.x1 < b.x2 && a.x2 > b.x1)
    ) cout << "LINE";
    // (c), (d) FACE
    else cout << "FACE";

    return 0;
}