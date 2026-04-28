#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001];
int praise[100001];
int ans[100001];

void dfs(int who, int praise_cnt){
    ans[who] = praise_cnt;
    for(auto k : v[who]){
        dfs(k, praise_cnt + praise[k]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int num; cin >> num;
        if(i > 1) v[num].push_back(i);
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        praise[a] += b;
    }

    dfs(1, praise[1]);

    for(int i=1;i<=n;i++) cout << ans[i] << " ";

    return 0;
}