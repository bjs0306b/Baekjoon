#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int arr[n][5];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    int cnt[n];
    memset(cnt, 0, 4*n);
    int cnt2[n];
    for (int i = 0; i < n; i++)
    {
        memset(cnt2, 0, 4*n);
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (arr[i][j] == arr[k][j])
                    cnt2[k] = 1;    
            }
        }
        cnt[i] = count(cnt2, cnt2+n, 1);
    }
    int mx = 0, ans;
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] > mx)
        {
            mx = cnt[i];
            ans = i + 1;
        }
    }
    cout << ans;

    return 0;
}