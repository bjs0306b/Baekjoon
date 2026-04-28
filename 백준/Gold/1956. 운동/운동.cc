#include <bits/stdc++.h>
using namespace std;

int edges[401][401];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            edges[i][j] = 4000001;
    for(int i=1;i<=v;i++) edges[i][i] = 0;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b] = c;
    }

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            for (int k = 1; k <= v; k++)
            {
                edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
            }
        }
    }

    int ans = 4000001;
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            if(i != j){
                ans = min(ans, edges[i][j] + edges[j][i]);
            }
        }
    }
    if(ans == 4000001) cout << -1;
    else cout << ans;

    return 0;
}