#include <bits/stdc++.h>
using namespace std;

bool visited[1000001];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int a,b; cin >> a >> b;

    queue<int> q; q.push(a); visited[a] = true;

    for(int ans=0;;ans++){
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front();
            q.pop();
            if(f == b){
                cout << ans;
                return 0;
            }

            if(f+1 < 1000001 && !visited[f+1]){
                q.push(f+1);
                visited[f+1] = true;
            }
            if(f*2 < 1000001 && !visited[f*2]){
                q.push(f*2);
                visited[f*2] = true;
            }
        }
    }

    return 0;
}