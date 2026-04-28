#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int n;

void dfs(int a[20][20], int cnt)
{
    if(cnt == 6) return;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, a[i][j]);
        
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << a[i][j] <<  " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";


    int temp[20][20];

    
    // move up
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = a[i][j];
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 1; i < n; i++)
            {
                if (temp[i - 1][j] == 0)
                {
                    temp[i - 1][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (temp[i-1][j] == temp[i][j])
            {
                temp[i - 1][j] *= 2;
                temp[i][j] = 0;
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 1; i < n; i++)
            {
                if (temp[i - 1][j] == 0)
                {
                    temp[i - 1][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    dfs(temp, cnt+1);

    // move down
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = a[i][j];
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = n-2; i >= 0; i--)
            {
                if (temp[i + 1][j] == 0)
                {
                    temp[i + 1][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
        for (int i = n-1; i>0; i--)
        {
            if (temp[i][j] == temp[i - 1][j])
            {
                temp[i][j] *= 2;
                temp[i - 1][j] = 0;
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = n-2; i >= 0; i--)
            {
                if (temp[i + 1][j] == 0)
                {
                    temp[i + 1][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    dfs(temp, cnt+1);

    // move left
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = a[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 1; j < n; j++)
            {
                if (temp[i][j-1] == 0)    
                {
                    temp[i][j-1] =temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (temp[i][j] == temp[i][j - 1])
            {
                temp[i][j-1] *= 2;
                temp[i][j] = 0;
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int j = 1; j < n; j++)
            {
                if (temp[i][j-1] == 0)    
                {
                    temp[i][j-1] =temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    dfs(temp, cnt+1);

    // move right
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = a[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = n-2; j >= 0; j--)
            {
                if (temp[i][j+1] == 0)
                {
                    temp[i][j+1] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
        for (int j = n-1; j>0; j--)
        {
            if (temp[i][j] == temp[i][j-1])
            {
                temp[i][j] *= 2;
                temp[i][j-1] = 0;
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int j = n-2; j >= 0; j--)
            {
                if (temp[i][j+1] == 0)
                {
                    temp[i][j+1] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    dfs(temp, cnt+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int arr[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    dfs(arr,0);

    cout << ans;

    return 0;
}