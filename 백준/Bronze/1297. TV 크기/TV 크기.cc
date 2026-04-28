#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double d, h, w;
    cin >> d >> h >> w;
    double ratio = sqrt((d * d) / (h * h + w * w));
    int H, W;
    H = h * ratio;
    W = w * ratio;
    cout << H << " " << W;

    return 0;
}