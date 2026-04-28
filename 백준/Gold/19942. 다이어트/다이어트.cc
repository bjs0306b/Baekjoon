#include <bits/stdc++.h>
using namespace std;

int ans = INT32_MAX;
vector<int> ans_v;

int nutri[15][5];
int n, mp, mf, ms, mv;

int total_p, total_f, total_s, total_v, total_cos;
bool visited[15];

void dfs(int m){

    if(m == n+1) return;

    if(total_p >= mp && total_f >= mf && total_s >= ms && total_v >= mv){
        if(total_cos < ans){
            ans = total_cos;
            ans_v.clear();
            for(int i=0;i<n;i++){
                if(visited[i]){
                    ans_v.push_back(i);
                }
            }
            return;
        }
    }
    else{
        visited[m] = true;
        total_p += nutri[m][0];
        total_f += nutri[m][1];
        total_s += nutri[m][2];
        total_v += nutri[m][3];
        total_cos += nutri[m][4];

        dfs(m+1);

        visited[m] = false;
        total_p -= nutri[m][0];
        total_f -= nutri[m][1];
        total_s -= nutri[m][2];
        total_v -= nutri[m][3];
        total_cos -= nutri[m][4];

        dfs(m+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> mp >> mf >> ms >> mv;
    
    for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin >> nutri[i][j];

    dfs(0);

    if(ans_v.size()){
        cout << ans << '\n';
        for(auto k : ans_v) cout << k+1 << " ";
    }
    else cout << -1;
    

    return 0;
}