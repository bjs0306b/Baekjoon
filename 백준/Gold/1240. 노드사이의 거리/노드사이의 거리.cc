#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[1001];
int dis[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n-1;i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=0;i<1001;i++) for(int j=0;j<1001;j++) dis[i][j] = INT32_MAX;

    for(int i=1;i<=n;i++){
        int start = i;
        priority_queue<pair<int,int>> pq;
        pq.push({0, i});
        dis[i][i] = 0;

        while(!pq.empty()){
            int cost = -pq.top().first, here = pq.top().second; pq.pop();
            if(dis[i][here] < cost) continue;

            for(int j=0;j<v[here].size();j++){
                int there = v[here][j].first;
                int nextDist = cost + v[here][j].second;

                if(dis[i][there] > nextDist){
                    dis[i][there] = nextDist;
                    pq.push({-nextDist, there});
                }
            }
        }
    }

    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        cout << dis[a][b] << "\n";
    }

    return 0;
}