#include <bits/stdc++.h>
using namespace std;

int ans = 0;

map<int,bool> visited;

int n;

int dx[4] = {1,5,10,50};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    queue<int> q; q.push(0);
    for(int i=0;i<n;i++){
        int size = q.size();
        set<int> visited;
        for(int j=0;j<size;j++){
            int f = q.front(); q.pop();
            for(int k=0;k<4;k++){
                int nx = f + dx[k];
                if(visited.find(nx) == visited.end()){
                    visited.insert(nx);
                    q.push(nx);
                }
            }
        }
    }

    cout << q.size();

    return 0;
}