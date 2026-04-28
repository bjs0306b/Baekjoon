#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> v; // false : >, true : <
int ans[10];
bool visited[10];
bool flag = true;

void dfs(int dep, int s, bool up){
    if(dep == n+1 && flag){
        for(int i=0;i<n+1;i++) cout << ans[i];
        cout << '\n';
        flag = false;
        return;
    }

    if(up){
        for(int i=s;i<10;i++){
            if(!visited[i]){
                ans[dep] = i;
                visited[i] = true;
                dfs(dep+1, i, v[dep]);
                visited[i] = false;
            }
        }
    }
    else{
        for(int i=s;i>=0;i--){
            if(!visited[i]){
                ans[dep] = i;
                visited[i] = true;
                dfs(dep+1, i, v[dep]);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        char c; cin >> c;
        if(c == '>') v.push_back(false);
        else v.push_back(true);
    }

    dfs(0, 9, false); // max
    flag = true;
    dfs(0, 0, true); // min
    
    return 0;
}