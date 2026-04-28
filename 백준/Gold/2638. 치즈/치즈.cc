#include <bits/stdc++.h>
using namespace std;
int a, b;
int arr[100][100];

void air(int x, int y)
{
    arr[x][y] = 2;
    if (x + 1 < a && arr[x + 1][y] == 0)
        air(x + 1, y);
    if (x > 0 && arr[x - 1][y] == 0)
        air(x - 1, y);
    if (y + 1 < b && arr[x][y + 1] == 0)
        air(x, y + 1);
    if (y > 0 && arr[x][y - 1] == 0)
        air(x, y - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            cin >> arr[i][j];

    air(0,0);
    int ans = 0;

    // cout << "\n";

    // for (int i = 0; i < a; i++)
    // {
    //     for (int j = 0; j < b; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    for (;;)
    {
        int cnt = 0;
        vector<pair<int, int>> vec;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (arr[i][j] == 1)
                {
                    cnt++;
                    int temp = 0;
                    if (i + 1 < a && arr[i + 1][j] == 2)
                        temp++;
                    if (i > 0 && arr[i - 1][j] == 2)
                        temp++;
                    if (j + 1 < b && arr[i][j + 1] == 2)
                        temp++;
                    if (j > 0 && arr[i][j - 1] == 2)
                        temp++;
                    if (temp > 1)
                    {
                        arr[i][j] = 0;
                        vec.push_back({i, j});
                    }
                }
            }
        }
        for (auto k : vec)
        {
            air(k.first, k.second);
        }
        if (cnt == 0)
            break;
        ans++;

        // for (int i = 0; i < a; i++)
        // {
        //     for (int j = 0; j < b; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    cout << ans;

    return 0;
}

// 처음에 치즈가 없는 곳에서 시작해서 공기가 통하는 곳을 표시.
// 너비 우선으로 해야될듯.
// 치즈가 사라져서 공기가 안통하던 곳이 공기가 통하면 이것도 다시 갱신해야 할듯.
