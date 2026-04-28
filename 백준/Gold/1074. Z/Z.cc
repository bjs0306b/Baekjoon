#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int a, b, c;
int cnt = 0;

void dfs(int i, int j, int size)
{
    if (size == 1)
    {
        if (i == b && j == c)
        {
            cout << cnt;
            return;
        }
        cnt++;
    }
    else
    {
        if (i <= b && b < i + size/2 && j <= c && c < j + size/2)
            dfs(i, j, size / 2);
        else if (i <= b && b < i + size/2 && j + size/2 <= c && c < j + size)
        {
            cnt += (size / 2) * (size / 2);
            dfs(i, j + size / 2, size / 2);
        }
        else if (i + size/2 <= b && b < i + size && j <= c && c < j + size/2)
        {
            cnt += (size / 2) * (size / 2) * 2;
            dfs(i + size / 2, j, size / 2);
        }
        else
        {
            cnt += (size / 2) * (size / 2) * 3;
            dfs(i + size / 2, j + size / 2, size / 2);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    dfs(0, 0, pow(2, a));
    return 0;
}
