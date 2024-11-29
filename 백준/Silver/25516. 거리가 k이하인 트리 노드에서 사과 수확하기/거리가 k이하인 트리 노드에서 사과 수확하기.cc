#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[100001];
bool exist_apple[100001];
int ans;

void dfs(int num, int dis){
    if(dis > k) return;

    if(exist_apple[num]) ans++;
    for(auto child : v[num]){
        dfs(child, dis+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;

    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i=0;i<n;i++) cin >> exist_apple[i];


    dfs(0,0);

    cout << ans;

    return 0;
}