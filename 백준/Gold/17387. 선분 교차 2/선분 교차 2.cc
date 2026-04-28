#include <bits/stdc++.h>
using namespace std;

struct point{
    long long x,y;
} p1,p2,p3,p4;

int ccw(point a, point b, point c){
    long long A = b.x - a.x;
    long long B = b.y - a.y;
    long long C = c.x - a.x;
    long long D = c.y - a.y;

    long long temp = A*D - B*C;
    if(temp > 0) return 1;
    else if(temp < 0) return -1;
    else return 0;
}

bool inLine(int a, int b, int c, int d)
{
    if (a > b) // b가 더 크게
    {
        swap(a, b);
    }
    if (c > d) // d가 더 크게
    {
        swap(c, d);
    }
    return (a <= d && b >= c) || (c <= b && d >= a); // 좌표의 대소 관계 확인
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    int f1 = ccw(p1,p2,p3), f2 = ccw(p1,p2,p4), f3 = ccw(p3,p4,p1), f4 = ccw(p3,p4,p2);

    if(f1 * f2 == 0 && f3 * f4 == 0){
        if(inLine(p1.x,p2.x,p3.x,p4.x) && inLine(p1.y, p2.y, p3.y, p4.y)) cout << 1;
        else cout << 0;
    }
    else if( f1 * f2 <= 0 && f3 * f4 <= 0) cout << 1;
    else cout << 0;

    return 0;
}