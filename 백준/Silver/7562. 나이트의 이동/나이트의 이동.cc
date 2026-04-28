#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int siz, ax, ay, bx, by;
bool arr[300][300];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> siz >> ax >> ay >> bx >> by;
        int cnt = 0;
        bool check = false;
        deque<pair<int, int>> dq;
        dq.push_back({ax, ay});
        arr[ax][ay] = true;
        if(ax == bx && ay == by){
            cout << 0 << "\n";
            continue;
        }
        while (!dq.empty())
        {
            int si = dq.size();
            for (int k = 0; k < si; k++)
            {
                int i = dq.front().first, j = dq.front().second;
                dq.pop_front();
                if (i - 2 >= 0 && j - 1 >= 0 && !arr[i - 2][j - 1])
                {
                    if (i - 2 == bx && j - 1 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i - 2, j - 1});
                    arr[i - 2][j - 1] = true;
                }
                if (i - 2 >= 0 && j + 1 < siz && !arr[i - 2][j + 1])
                {
                    if (i - 2 == bx && j + 1 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i - 2, j + 1});
                    arr[i - 2][j + 1] = true;
                }
                if (i - 1 >= 0 && j - 2 >= 0 && !arr[i - 1][j - 2])
                {
                    if (i - 1 == bx && j - 2 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i - 1, j - 2});
                    arr[i - 1][j - 2] = true;
                }
                if (i - 1 >= 0 && j + 2 < siz && !arr[i - 1][j + 2])
                {
                    if (i - 1 == bx && j + 2 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i - 1, j + 2});
                    arr[i - 1][j + 2] = true;
                }
                if (i + 1 < siz && j - 2 >= 0 && !arr[i + 1][j - 2])
                {
                    if (i + 1 == bx && j - 2 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i + 1, j - 2});
                    arr[i + 1][j - 2] = true;
                }
                if (i + 1 < siz && j + 2 < siz && !arr[i + 1][j + 2])
                {
                    if (i + 1 == bx && j + 2 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i + 1, j + 2});
                    arr[i + 1][j + 2] = true;
                }
                if (i + 2 < siz && j - 1 >= 0 && !arr[i + 2][j - 1])
                {
                    if (i + 2 == bx && j - 1 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i + 2, j - 1});
                    arr[i + 2][j - 1] = true;
                }
                if (i + 2 < siz && j + 1 < siz && !arr[i + 2][j + 1])
                {
                    if (i + 2 == bx && j + 1 == by)
                    {
                        cout << cnt + 1 << "\n";
                        check = true;
                        break;
                    }
                    dq.push_back({i + 2, j + 1});
                    arr[i + 2][j + 1] = true;
                }
            }
            if (check)
                break;
            cnt++;
        }
        memset(arr, 0, sizeof(arr));
    }

    return 0;
}
