#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<bool> number(10, true);
    while (m--)
    {
        int num;
        cin >> num;
        number[num] = false;
    }

    vector<pair<int, int>> v;
    v.push_back({100, 0});
    if (number[0])
        v.push_back({0, 1});

    queue<int> q;
    for (int i = 1; i < 10; i++)
    {
        if (number[i])
        {
            q.push(i);
            v.push_back({i, 1});
        }
    }

    int cnt = 1;
    while (!q.empty())
    {   
        cnt++;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int f = q.front();
            q.pop();

            for (int j = 0; j < 10; j++)
            {
                if (number[j] && f * 10 + j <= 5000000)
                {
                    q.push(f * 10 + j );
                    v.push_back({f*10 +j, cnt});
                }
            }
        }
    }

    int mn = INT32_MAX;
    for(int i=0;i<v.size();i++){
        auto temp = v[i];
        mn = min(mn, abs(temp.first - n) + temp.second);
    }
    cout << mn;

    return 0;
}