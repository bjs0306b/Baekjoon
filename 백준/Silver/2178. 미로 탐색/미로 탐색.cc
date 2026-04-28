#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    bool arr[a][b];
    short dp[a][b];
    for (int i = 0; i < a; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < b; j++)
        {
            int num = s[j] - '0';
            arr[i][j] = num;
        }
    }
    dp[0][0] = 1;
    arr[0][0] = 0;
    deque<pair<int, int>> deq;
    deq.push_back({0, 0});
    while (!deq.empty())
    {
        int p = deq.front().first, q = deq.front().second;
        deq.pop_front();
        if (p > 0 && arr[p - 1][q] == 1)
        {
            deq.push_back({p - 1, q});
            dp[p - 1][q] = dp[p][q] + 1;
            arr[p - 1][q] = 0;
        }
        if (p < a - 1 && arr[p + 1][q] == 1)
        {
            deq.push_back({p + 1, q});
            dp[p + 1][q] = dp[p][q] + 1;
            arr[p + 1][q]=0;
        }
        if (q > 0 && arr[p][q - 1] == 1)
        {
            deq.push_back({p, q - 1});
            dp[p][q - 1] = dp[p][q] + 1;
            arr[p][q - 1]=0;
        }
        if (q < b - 1 && arr[p][q + 1] == 1)
        {
            deq.push_back({p, q + 1});
            dp[p][q + 1] = dp[p][q] + 1;
            arr[p][q + 1]=0;
        }
    }
    cout << dp[a - 1][b - 1];
    return 0;
}