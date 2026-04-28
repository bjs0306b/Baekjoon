#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n,m,l,x; cin >> n >> m >> l >> x;
//     bool visited[n+1]; memset(visited, false, sizeof(visited));
//     int dis[n+1]; memset(dis, n, sizeof(dis));
//     vector<int> arr[n+1];
//     for(int i=0;i<m;i++){
//         int a,b; cin >> a >> b;
//         arr[a].push_back(b);
//     }
//     dis[x]=0; visited[x] = true;
//     priority_queue<int> pq;
//     for(auto k : arr[x]){
//         pq.push(k);
//         dis[k] = 1;
//         visited[k] = true;
//     }
//     while(!pq.empty()){
//         int temp = pq.top();
//         pq.pop();   
//         for(auto k : arr[temp]){
//             dis[k] = min(dis[temp] + 1, dis[k]);
//             if(!visited[k]) pq.push(k);
//         }   
//     }
//     set<int> ans;
//     for(int i=1;i<=n;i++){
//        if(dis[i] == l) ans.insert(i);
//     }
//     if(ans.empty()){
//         cout << -1;
//     }
//     else for(auto k : ans) cout << k << "\n";

//     return 0;
// }

int dis[300001];
bool visited[300001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,n,l,x; cin >> n >> m >> l >> x;
    vector<int> v[n+1];
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
    }
    int d = 0;
    dis[x] = 0;
    visited[x] = true;
    queue<int> q; q.push(x);
    bool check = false;
    set<int> ans;
    while(!q.empty()){
        int size = q.size();
        d++;
        for(int i=0;i<size;i++){
            int temp = q.front();
            q.pop();
            for(auto k : v[temp]){
                if(!visited[k]){
                    if(d == l){check = true; ans.insert(k);}
                    else{
                        dis[k] = d;
                        q.push(k);
                        visited[k] = true;
                    }
                }
            }
        }
        if(check) break;
    }
    if(ans.empty()) cout << -1;
    else for(auto k : ans) cout << k << "\n";
    return 0;
}