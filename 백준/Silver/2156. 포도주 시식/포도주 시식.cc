#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n], dp[10001];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, 0, 40004);
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max({arr[0]+arr[1], arr[1]+arr[2], arr[0]+arr[2]});
    if (n > 2)
    {
        for (int i = 3; i < n; i++)
        {
            dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
            dp[i] = *max_element(dp, dp+i+1);
        }
    }
    cout << *max_element(dp, dp + n);

    return 0;
}