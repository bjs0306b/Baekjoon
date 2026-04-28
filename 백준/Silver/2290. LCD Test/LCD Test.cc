#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<vector<char>> arr(23, vector<char>(130, ' '));

void func(int pos, int num)
{
    switch (num)
    {
    case 1:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                arr[i][pos * (n + 3) + n + 1] = '|';
            }
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                if (i < n + 1)
                    arr[i][pos * (n + 3) + n + 1] = '|';
                else
                    arr[i][pos * (n + 3)] = '|';
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    arr[i][pos * (n + 3) + j] = '-';
                }
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                arr[i][pos * (n + 3) + n + 1] = '|';
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    arr[i][pos * (n + 3) + j] = '-';
                }
            }
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                arr[i][pos * (n + 3) + n + 1] = '|';
                if (i < n + 1)
                    arr[i][pos * (n + 3)] = '|';
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    if (i != 0 && i != 2 * n + 2)
                        arr[i][pos * (n + 3) + j] = '-';
                }
            }
        }
        break;
    }
    case 5:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                if (i >= n + 1)
                    arr[i][pos * (n + 3) + n + 1] = '|';
                else
                    arr[i][pos * (n + 3)] = '|';
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    arr[i][pos * (n + 3) + j] = '-';
                }
            }
        }
        break;
    }
    case 6:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                if (i >= n + 1)
                    arr[i][pos * (n + 3) + n + 1] = '|';
                arr[i][pos * (n + 3)] = '|';
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    arr[i][pos * (n + 3) + j] = '-';
                }
            }
        }
        break;
    }
    case 7:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                arr[i][pos * (n + 3) + n + 1] = '|';
            }
            else
            {
                if (i == 0)
                {
                    for (int j = 1; j < n + 1; j++)
                    {
                        arr[i][pos * (n + 3) + j] = '-';
                    }
                }
            }
        }
        break;
    }
    case 8:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                arr[i][pos * (n + 3) + n + 1] = '|';
                arr[i][pos * (n + 3)] = '|';
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    arr[i][pos * (n + 3) + j] = '-';
                }
            }
        }
        break;
    }
    case 9:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                arr[i][pos * (n + 3) + n + 1] = '|';
                if (i < n + 1)
                    arr[i][pos * (n + 3)] = '|';
            }
            else
            {
                for (int j = 1; j < n + 1; j++)
                {
                    arr[i][pos * (n + 3) + j] = '-';
                }
            }
        }
        break;
    }
    case 0:
    {
        for (int i = 0; i < 2 * n + 3; i++)
        {
            if (!(i == 0 || i == 2 * n + 2 || i == n + 1))
            {
                arr[i][pos * (n + 3) + n + 1] = '|';
                arr[i][pos * (n + 3)] = '|';
            }
            else
            {
                if(i == 0 || i == 2*n+2){
                    for (int j = 1; j < n + 1; j++)
                    {
                        arr[i][pos * (n + 3) + j] = '-';
                    }
                }
            }
        }
        break;
    }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - '0';
        func(i, num);
    }

    for (int i = 0; i < 2 * n + 3; i++)
    {
        for (int j = 0; j < (n + 3) * s.size(); j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}