#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int arr[15][15], n, cnt = 0;
bool visited[15];
void func(int a, int b, int c)
{
    for (int i = a, j = b; i >= 0 && i < n && j >= 0 && j < n; i++, j--)
    {
        if(!arr[i][j]) arr[i][j] = c;
    }
    for (int i = a, j = b; i >= 0 && i < n && j >= 0 && j < n; i++, j++)
    {
        if(!arr[i][j])arr[i][j] = c;
    }
}

void del(int a, int b, int c)
{
    for (int i = a, j = b; i >= 0 && i < n && j >= 0 && j < n; i++, j--)
    {
        if(arr[i][j] == c) arr[i][j] = 0;
    }
    for (int i = a, j = b; i >= 0 && i < n && j >= 0 && j < n; i++, j++)
    {
        if(arr[i][j] == c) arr[i][j] = 0;
    }
}
void dfs(int a, int b)
{
    if (a == n - 1)
    {
        cnt++;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if(!visited[i]){
                visited[i]= true;
                func(a, b, a+1);
                if(!arr[a + 1][i]) dfs(a + 1, i);
                del(a,b, a+1);
                visited[i] = false;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        memset(arr, 0, 4 * 15 * 15);
        memset(visited, false, 15);
        visited[i] = true;
        dfs(0, i);
    }
    cout << cnt;

    return 0;
}