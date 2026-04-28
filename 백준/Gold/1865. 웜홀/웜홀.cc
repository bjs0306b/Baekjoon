#include <bits/stdc++.h>
using namespace std;
int a, b, c;
long long dis[501];
struct node
{
    int from, to, cost;
};
vector<node> vec;

bool bf(int start)
{
    for (int i = 1; i <= a; i++)
    {
        for (auto k : vec)
        {
            int from = k.from;
            int to = k.to;
            int cost = k.cost;

            if (dis[to] > dis[from] + cost)
            {
                if(i == a) return true;
                dis[to] = dis[from] + cost;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        while (b--)
        {
            int f, t, c;
            cin >> f >> t >> c;
            vec.push_back({f, t, c});
            vec.push_back({t, f, c});
        }
        while (c--)
        {
            int f, t, c;
            cin >> f >> t >> c;
            c *= -1;
            vec.push_back({f, t, c});
        }

        for (int i = 1; i <= a; i++)
            dis[i] = INT32_MAX;
        dis[1] = 0;

        if (bf(1))
            cout << "YES\n";
        else
            cout << "NO\n";

        vec.clear();
    }

    return 0;
}