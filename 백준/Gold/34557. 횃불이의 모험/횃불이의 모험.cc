#include <bits/stdc++.h>
using namespace std;

int n, m, A[100][100];
int key_event[4]; // WASD, 1 : Down, 2 : Stay, 3: Up
map<char, int> B;
string input;
int cur_x, cur_y;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 2)
                cur_x = i, cur_y = j;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        if (s == "Down")
            key_event[i] = 1;
        else if (s == "Stay")
            key_event[i] = 2;
        else if (s == "Up")
            key_event[i] = 3;
    }
    B['W'] = 0, B['A'] = 1, B['S'] = 2, B['D'] = 3;
    cin >> input;

    if (key_event[B[input[0]]] == 1) // 처음 누른 것의 이벤트가 Down이면 움직여야 함.
    {
        int nx = cur_x + dx[B[input[0]]], ny = cur_y + dy[B[input[0]]];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
        {
            cur_x = nx, cur_y = ny;
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (input[i] != input[i - 1])
        {
            bool flag1 = false, flag2 = false;
            if (key_event[B[input[i - 1]]] == 3) // Up
            {
                flag1 = true;
            }
            if (key_event[B[input[i]]] == 1) // Down
            {
                flag2 = true;
            }
            if (flag1 && flag2)
            { // 동시에 이벤트 발생 시 WASD 순으로
                if (B[input[i - 1]] < B[input[i]])
                {
                    int nx = cur_x + dx[B[input[i - 1]]], ny = cur_y + dy[B[input[i - 1]]];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
                    {
                        cur_x = nx, cur_y = ny;
                    }
                    nx = cur_x + dx[B[input[i]]], ny = cur_y + dy[B[input[i]]];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
                    {
                        cur_x = nx, cur_y = ny;
                    }
                }
                else
                {
                    int nx = cur_x + dx[B[input[i]]], ny = cur_y + dy[B[input[i]]];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
                    {
                        cur_x = nx, cur_y = ny;
                    }
                    nx = cur_x + dx[B[input[i - 1]]], ny = cur_y + dy[B[input[i - 1]]];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
                    {
                        cur_x = nx, cur_y = ny;
                    }
                }
            }
            else
            {
                if (flag1)
                {
                    int nx = cur_x + dx[B[input[i - 1]]], ny = cur_y + dy[B[input[i - 1]]];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
                    {
                        cur_x = nx, cur_y = ny;
                    }
                }
                if (flag2)
                {
                    int nx = cur_x + dx[B[input[i]]], ny = cur_y + dy[B[input[i]]];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
                    {
                        cur_x = nx, cur_y = ny;
                    }
                }
            }
        }
        else
        {
            if (key_event[B[input[i]]] == 2) // Stay
            {
                int nx = cur_x + dx[B[input[i]]], ny = cur_y + dy[B[input[i]]];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != 1)
                {
                    cur_x = nx, cur_y = ny;
                }
            }
        }
    }
    cout << cur_x+1 << " " << cur_y+1;

    return 0;
}