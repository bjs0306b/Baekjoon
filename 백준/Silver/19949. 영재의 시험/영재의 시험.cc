#include <bits/stdc++.h>
using namespace std;

vector<int> v(10);

int ans = 0;

void dfs(int dep, int pre, int prepre, int score){
    if(dep == 10){
        if(score > 4) ans++;
        return;
    }
    for(int i=1;i<=5;i++){
        if(i == pre && pre == prepre) continue;

        if(i == v[dep]) dfs(dep+1, i, pre, score+1);
        else dfs(dep+1, i, pre, score);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<10;i++) cin >> v[i];

    dfs(0,0,0,0);

    cout << ans;
    
    return 0;
}