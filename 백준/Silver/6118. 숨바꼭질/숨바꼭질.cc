#include <bits/stdc++.h>
using namespace std;

vector<int> v[20001];
bool visited[20001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int s,e; cin >> s >> e;
        v[s].push_back(e); v[e].push_back(s);
    }
    
    queue<int> q, temp;
    q.push(1);
    visited[1] = true;
    int ans1=INT32_MAX,ans2 = -1, ans3; // depth
    while(!q.empty()){
        int size = q.size();
        temp = q;
        ans2++;
        for(int i=0;i<size;i++){
            int f = q.front(); q.pop();
            for(auto k : v[f]){
                if(!visited[k]){
                    visited[k] =true;
                    q.push(k);
                }
            }
        }     
    }

    ans3 = temp.size();
    while(!temp.empty()){
        ans1 = min(ans1, temp.front());
        temp.pop();
    }

    cout << ans1 << " "  << ans2 << " " << ans3;




    return 0;
}