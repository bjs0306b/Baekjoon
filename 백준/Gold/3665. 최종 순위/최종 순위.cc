#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
bool A[501][501];
int ranking[501];

void input(){
    cin >> n;
    v.resize(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) A[i][j] = false;
    for(int i=1;i<=n;i++) ranking[i] = 0;
    
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            A[v[i]][v[j]] = true;
            ranking[v[j]]++;
        }
    }

    cin >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        if(A[a][b]){
            A[a][b] = false;
            A[b][a] = true;
            ranking[b]--;
            ranking[a]++;
        }
        else{
            A[a][b] = true;
            A[b][a] = false;
            ranking[b]++;
            ranking[a]--;
        }
    }
}

void solve(){
    queue<int> q;
    vector<int> temp;
    for(int i=1;i<=n;i++){
        if(ranking[i] == 0){
            q.push(i);
            temp.push_back(i);
        }
    }

    while(!q.empty()){
        int f = q.front();
        q.pop();

        ranking[f]--;

        for(int i=1;i<=n;i++){
            if(A[f][i]){
                if(--ranking[i] == 0){
                    temp.push_back(i);
                    q.push(i);
                }
            }
        }
    }

    if(temp.size() == n){
        for(auto k : temp) cout << k << " ";
        cout << "\n";
    }
    else cout << "IMPOSSIBLE\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        input();
        solve();
    }
    
    return 0;
}