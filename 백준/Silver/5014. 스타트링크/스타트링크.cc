#include <bits/stdc++.h>
using namespace std;

int ans(){
    int f,s,g,u,d; cin >> f >> s >> g >> u >> d;

    vector<bool> visited(f+1, false);
    queue<int> q; q.push(s); visited[s] = true;

    int tm = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int fnt = q.front(); q.pop();

            if(fnt == g) return tm;

            if(fnt+u <= f && !visited[fnt+u]){
                visited[fnt+u] = true;
                q.push(fnt+u);
            }
            if(fnt-d > 0 && !visited[fnt-d]){
                visited[fnt-d] = true;
                q.push(fnt-d);
            }
        }
        tm++;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k = ans();
    if(k >= 0) cout << k;
    else cout << "use the stairs";
    
    return 0;
}