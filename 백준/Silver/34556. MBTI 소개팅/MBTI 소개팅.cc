#include <bits/stdc++.h>
using namespace std;
int n, ans; 
vector<string> male, female;
bool visited[10];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        male.push_back(s);
    }
    for(int i=0;i<n;i++){
        string s; cin >> s;
        female.push_back(s);
    }
}

int ret_score(int a, int b){
    int ret = 0;
    for(int i=0;i<4;i++){
        if(male[a][i] != female[b][i]) ret++;
    }
    return ret;
}

void dfs(int dep, int sum){
    if(dep == n){
        ans = max(ans, sum);
        return;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(dep+1, sum + ret_score(dep, i));
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    dfs(0, 0);
    cout << ans;
    
    return 0;
}