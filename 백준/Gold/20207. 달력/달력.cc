#include <bits/stdc++.h>
using namespace std;

int arr[366];
int ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        int s, e;
        cin >> s >> e;
        for (int i = s; i <= e; i++)
            arr[i]++;
    }

    int b = 0;
    for (int i = 0; i < 366; i++)
    {
        if (!b && arr[i])
        {
            b = i;
        }

        if (b && !arr[i])
        {
            int mx = *max_element(arr + b, arr + i);
            ans += (i - b) * mx;
            b = 0;
        }
    }
    if (b)
    {
        int mx = *max_element(arr + b, arr + 366);
        ans += (366 - b) * mx;
    }

    cout << ans;

    return 0;
}