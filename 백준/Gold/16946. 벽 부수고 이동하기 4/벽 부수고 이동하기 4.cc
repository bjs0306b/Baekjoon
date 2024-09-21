#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[1001][1001];
int cnt[1001][1001]; // 0인 곳이 몇개가 이어져있는 지 표시하는 cnt
bool visited[1001][1001];
bool visited2[1001][1001];

void dfs3(int x, int y, int num)
{

    if (x > 0 && arr[x - 1][y] == 0)
    {
        if (cnt[x - 1][y] == 0)
        {
            cnt[x - 1][y] = num;
            dfs3(x - 1, y, num);
        }
    }
    if (x > 0 && arr[x - 1][y] != 0)
    {
        if(!visited2[x-1][y]){
            visited2[x-1][y] = true;
            arr[x-1][y] += num;
        }
    }

    if (x+1 < m && arr[x + 1][y] == 0)
    {
        if (cnt[x + 1][y] == 0)
        {
            cnt[x + 1][y] = num;
            dfs3(x + 1, y, num);
        }
      
    }
     if (x+1 < m && arr[x + 1][y] != 0)
    {

        if(!visited2[x+1][y]){
            visited2[x+1][y] = true;
            arr[x+1][y] += num;
        }
    }

    if (y > 0 && arr[x ][y-1] == 0)
    {
        if (cnt[x ][y-1] == 0)
        {
            cnt[x ][y-1] = num;
            dfs3(x , y-1, num);
        }
       
    }
    if (y > 0 && arr[x ][y-1] != 0)
    {
       
        if(!visited2[x][y-1]){
            visited2[x][y-1] = true;
            arr[x][y-1] += num;
        }
    }

    if (y +1 < n && arr[x ][y+1] == 0)
    {
        if (cnt[x ][y+1] == 0)
        {
            cnt[x ][y+1] = num;
            dfs3(x , y+1, num);
        }
   
    }
    if (y +1 < n && arr[x ][y+1] != 0)
    {
       
        if(!visited2[x][y+1]){
            visited2[x][y+1] = true;
            arr[x][y+1] += num;
        }
    }
}

int dfs2(int x, int y)
{
    int r = 1;
    if (x > 0 && arr[x - 1][y] == 0 && !visited[x - 1][y])
    {
        visited[x - 1][y] = true;
        r += dfs2(x - 1, y);
    }
    if (y > 0 && arr[x][y - 1] == 0 && !visited[x][y - 1])
    {
        visited[x][y - 1] = true;
        r += dfs2(x, y - 1);
    }
    if (x + 1 < m && arr[x + 1][y] == 0 && !visited[x + 1][y])
    {
        visited[x + 1][y] = true;
        r += dfs2(x + 1, y);
    }
    if (y + 1 < n && arr[x][y + 1] == 0 && !visited[x][y + 1])
    {
        visited[x][y + 1] = true;
        r += dfs2(x, y + 1);
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0 && cnt[i][j] == 0)
            {
                visited[i][j] = true;
                cnt[i][j] = dfs2(i, j);

                for (int k = 0; k < m; k++)
                    for (int r = 0; r < n; r++)
                        visited2[k][r] = false;
                dfs3(i, j, cnt[i][j]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] % 10;
            // << cnt[i][j];
        }
        cout << "\n";
    }

    return 0;
}