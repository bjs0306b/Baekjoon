#include <bits/stdc++.h>
using namespace std;

int n;
char cookie[1000][1000];
int ans[5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cookie[i][j];

    pair<int, int> heart;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            bool flag = true;
            for (int k = 0; k < 4; k++)
            {
                if (cookie[i + dx[k]][j + dy[k]] != '*')
                    flag = false;
            }
            if (flag)
            {
                heart = {i, j};
                cout << i + 1 << " " << j + 1 << "\n";
                break;
            }
        }
    }

    pair<int, int> temp = heart;
    while (temp.second != 0 && cookie[temp.first][--temp.second] == '*')
        ans[0]++;
    temp = heart;
    while (temp.second != n - 1 && cookie[temp.first][++temp.second] == '*')
        ans[1]++;
    temp = heart;
    while (temp.first != n - 1 && cookie[++temp.first][temp.second] == '*')
        ans[2]++;

    temp.first--;
    pair<int, int> wrist_lowest = temp;

    temp.second--;
    while (temp.first != n - 1 && cookie[++temp.first][temp.second] == '*')
        ans[3]++;

    temp = wrist_lowest;
    
    temp.second++;
    while (temp.first != n - 1 && cookie[++temp.first][temp.second] == '*')
        ans[4]++;

    for (int i = 0; i < 5; i++)
        cout << ans[i] << " ";

    return 0;
}