#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
char arr[52][52];
int n, mx = 1;

void func()
{
    for (int i = 1; i <= n; i++)
    {
        int cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == arr[i][j + 1])
            {
                cnt++;
            }
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
    }
    
    for (int i = 1; i <= n; i++)
    {
        int cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (arr[j][i] == arr[j + 1][i])
            {
                cnt++;
            }
            else
            {
                mx = max(mx, cnt);
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] != arr[i][j + 1])
            {
                swap(arr[i][j], arr[i][j + 1]);
                func();
                swap(arr[i][j], arr[i][j + 1]);
            }

            if (arr[j][i] != arr[j + 1][i])
            {
                swap(arr[j][i], arr[j + 1][i]);
                func();
                swap(arr[j][i], arr[j + 1][i]);
            }
        }
    }
    cout << mx;

    return 0;
}