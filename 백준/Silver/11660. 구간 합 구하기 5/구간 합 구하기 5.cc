#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int arr[a + 1][a + 1];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= a; j++)
        {
            cin >> arr[i][j];
            arr[i][j] += arr[i][j - 1];
        }
    for (int i = 0; i < b; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int j = x1; j <= x2; j++)
        {
            ans += (arr[j][y2] - arr[j][y1-1]);
        }
        cout << ans << "\n";
    }

    return 0;
}