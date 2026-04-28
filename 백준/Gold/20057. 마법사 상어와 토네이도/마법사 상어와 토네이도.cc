#include <bits/stdc++.h>
using namespace std;
int n;
int arr[500][500];
int ans = 0;
void func(int x, int y, int dir)
{ // dir : 1은 동 2는 북 3은 서 4는 남
    if (dir == 1)
    {
        int dx[9] = {-2, -1, -1, -1, 0, 1, 1, 1, 2}, dy[9] = {0, -1, 0, 1, 2, -1, 0, 1, 0}, percent[9] = {2, 1, 7, 10, 5, 1, 7, 10, 2};
        int temp = arr[x][y];
        for (int i = 0; i < 9; i++)
        {
            arr[x][y] -= (temp * percent[i] / 100);
            if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
            {
                arr[x + dx[i]][y + dy[i]] += (temp * percent[i] / 100);
            }
            else
            {
                ans += (temp * percent[i] / 100);
            }
        }
        if (y + 1 >= 0 && y + 1 < n)
            arr[x][y + 1] += arr[x][y];
        else
            ans += arr[x][y];

        arr[x][y] = 0;
    }
    else if (dir == 2)
    {
        int dx[9] = {-2, -1, -1, 0, 0, 0, 0, 1, 1}, dy[9] = {0, -1, 1, -2, -1, 1, 2, -1, 1}, percent[9] = {5, 10, 10, 2, 7, 7, 2, 1, 1};
        int temp = arr[x][y];
        for (int i = 0; i < 9; i++)
        {
            arr[x][y] -= (temp * percent[i] / 100);
            if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
            {
                arr[x + dx[i]][y + dy[i]] += (temp * percent[i] / 100);
            }
            else
            {
                ans += (temp * percent[i] / 100);
            }
        }
        if (x - 1 >= 0 && x - 1 < n)
            arr[x - 1][y] += arr[x][y];
        else
            ans += arr[x][y];

        arr[x][y] = 0;
    }
    else if (dir == 3)
    {
        int dx[9] = {-2, -1, -1, -1, 0, 1, 1, 1, 2}, dy[9] = {0, -1, 0, 1, -2, -1, 0, 1, 0}, percent[9] = {2, 10, 7, 1, 5, 10, 7, 1, 2};
        int temp = arr[x][y];
        for (int i = 0; i < 9; i++)
        {
            arr[x][y] -= (temp * percent[i] / 100);
            if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
            {
                arr[x + dx[i]][y + dy[i]] += (temp * percent[i] / 100);
            }
            else
            {
                ans += (temp * percent[i] / 100);
            }
        }
        if (y - 1 >= 0 && y - 1 < n)
            arr[x][y - 1] += arr[x][y];
        else
            ans += arr[x][y];

        arr[x][y] = 0;
    }
    else if (dir == 4)
    {
        int dx[9] = {-1, -1, 0, 0, 0, 0, 1, 1, 2}, dy[9] = {-1, 1, -2, -1, 1, 2, -1, 1, 0}, percent[9] = {1, 1, 2, 7, 7, 2, 10, 10, 5};
        int temp = arr[x][y];
        for (int i = 0; i < 9; i++)
        {
            arr[x][y] -= (temp * percent[i] / 100);
            if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
            {
                arr[x + dx[i]][y + dy[i]] += (temp * percent[i] / 100);
            }
            else
            {
                ans += (temp * percent[i] / 100);
            }
        }
        if (x + 1 >= 0 && x + 1 < n)
            arr[x + 1][y] += arr[x][y];
        else
            ans += arr[x][y];

        arr[x][y] = 0;
    }
}

void print(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "ans : " << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    int cur_x = n / 2, cur_y = n / 2;

    int iter = 1;
    int cnt = 0;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}, dz[4] = {3, 4, 1, 2};

    for (;;)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < iter; j++)
            {
                cur_x += dx[i], cur_y += dy[i];
                func(cur_x, cur_y, dz[i]);
                // cout << cur_x << " " << cur_y << " " << dz[i] <<  "\n";
                if (cur_x == 0 && cur_y == 0)
                {
                    //print();
                    cout << ans;
                    return 0;
                }
            }
            
            if (++cnt == 2)
            {
                cnt = 0;
                iter++;
            }
        }
    }
    return 0;
}