#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int arr[2187][2187];
int ans[3];
void dfs(int a, int b, int s)
{
    bool check = true;
    for (int i = (a / s) * s; i < (a / s) * s + s; i++)
    {
        for (int j = (b / s) * s; j < (b / s) * s + s; j++)
        {
            if (arr[i][j] != arr[a][b]){
                check = false;
                break;
            }
        }
        if(!check) break;
    }
    if (check)
    {
        dfs(a, b, 3 * s);
    }
    else
    {
        if (arr[a][b] == -1)
            ans[0]++;
        else if (arr[a][b] == 0)
            ans[1]++;
        else if (arr[a][b] == 1)
            ans[2]++;

        s /= 3;
        for (int i = (a / s) * s; i < (a / s) * s + s; i++)
        {
            for (int j = (b / s) * s; j < (b / s) * s + s; j++)
            {
                arr[i][j] = 2;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 2)
            {
                dfs(i, j, 1);
            }
        }
    }
    for (int i = 0; i < 3; i++)
        cout << ans[i] << "\n";
    return 0;
}