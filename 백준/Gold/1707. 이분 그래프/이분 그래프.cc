#include <bits/stdc++.h>
using namespace std;

bool ans()
{
    int v, e;
    cin >> v >> e;
    vector<int> vec[v + 1];
    vector<bool> colors(v + 1);
    vector<bool> visited(v + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    
    for (int j = 1; j <= v; j++)
    {
        if (!visited[j])
        {
            bool color = true;
            queue<int> q;
            q.push(j);
            visited[j] = true;
            colors[j] = false;
            
            while (!q.empty())
            {
                int size = q.size();
                for (int i = 0; i < size; i++)
                {
                    int f = q.front();
                    q.pop();
                    for (auto k : vec[f])
                    {
                        if (!visited[k])
                        {
                            q.push(k);
                            visited[k] = true;
                            colors[k] = color;
                        }
                    }
                }
                color = !color;
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        for (auto k : vec[i])
        {
            if (colors[i] == colors[k])
                return 0;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        if (ans())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}