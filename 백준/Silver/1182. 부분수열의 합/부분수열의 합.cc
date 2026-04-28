#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
int a, b, cnt = 0, arr[21];
vector<int> v;

void dfs(int n, int m, int s)
{
    if (n == m)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
            sum += arr[i];
        if (sum == b)
            cnt++;
    }
    else
    {
        for (int i = s; i < v.size(); i++)
        {
            arr[n] = v[i];
            dfs(n + 1, m, i + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 1; i <= a; i++)
    {
        dfs(0, i, 0);
    }
    cout << cnt;
    return 0;
}