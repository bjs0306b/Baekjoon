#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
struct node
{
    int m, s, d;
};
vector<node> v[50][50];
void command()
{
    vector<node> temp[50][50];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (auto k : v[i][j])
            {
                int nr = (i + 1000*N + dr[k.d] * k.s) % N, nc = (j + 1000*N + dc[k.d] * k.s) % N;
                temp[nr][nc].push_back({k.m, k.s, k.d});
            }
            v[i][j].clear();
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (temp[i][j].size() > 1)
            {
                
                int sum_m = 0, sum_s = 0, size = temp[i][j].size();
                bool all_odd = true, all_even = true;
                for (auto k : temp[i][j])
                {
                    sum_m += k.m;
                    sum_s += k.s;
                    if (k.d % 2)
                        all_even = false;
                    else
                        all_odd = false;
                }
                sum_m /= 5; 
                sum_s /= size;
                
                if (sum_m)
                {
                    if (all_odd || all_even)
                    {
                        for (int k = 0; k <= 7; k += 2)
                            v[i][j].push_back({sum_m, sum_s, k});
                    }
                    else
                    {
                        for (int k = 1; k <= 7; k += 2)
                            v[i][j].push_back({sum_m, sum_s, k});
                    }
                }
            }
            else{
                v[i][j] = temp[i][j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        r--, c--;
        v[r][c].push_back({m, s, d});
    }
    for (int i = 0; i < K; i++)
    {
        command();
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (auto k : v[i][j])
            {
                ans += k.m;
            }
        }
    }
    cout << ans;

    return 0;
}