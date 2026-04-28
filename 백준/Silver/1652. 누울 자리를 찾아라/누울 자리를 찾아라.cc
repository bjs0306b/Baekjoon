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
    int n;
    cin >> n;
    char arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '.')
                cnt++;
            else
            {
                if (cnt > 1)
                    cnt1++;
                cnt = 0;
            }
        }
        if(cnt > 1) cnt1++;
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == '.')
                cnt++;
            else
            {
                if (cnt > 1)
                    cnt2++;
                cnt = 0;
            }
        }
        if(cnt > 1) cnt2++;
    }
    cout << cnt1 << " " << cnt2;
    return 0;
}