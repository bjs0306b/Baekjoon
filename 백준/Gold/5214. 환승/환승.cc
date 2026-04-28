#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,k,m; cin >> n >> k >> m;
    bool visited[n+1]; for(int i=1;i<=n;i++) visited[i] = false;
    bool tube_visited[m]; for(int i=0;i<m;i++) tube_visited[i] = false;
    vector<int> v[m], index[n+1];

    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            int num; cin >> num;
            v[i].push_back(num);
            index[num].push_back(i);
        }
    }
    visited[1] = true;
    queue<int> q; q.push(1);

    int ans = 1;
    while(!q.empty()){
        
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front();
            q.pop();
            if(f == n){
                cout << ans;
                return 0;
            }

            for(int j=0;j<index[f].size();j++){
                int tube = index[f][j];
                if(tube_visited[tube]) continue;
                tube_visited[tube] = true;
                for(auto next_node : v[tube]){
                    if(f == next_node) continue;
                    if(!visited[next_node]){
                        visited[next_node] = true;
                        q.push(next_node);
                    }
                }
            }
        }
        ans++;
    }
    cout << -1;
    return 0;
}