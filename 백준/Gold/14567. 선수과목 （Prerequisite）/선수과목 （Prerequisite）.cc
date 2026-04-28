#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v[1001];
int degree[1001];
int A[1001];
int tmm = 2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) if(degree[i] == 0){q.push(i); A[i] = 1;}
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int front = q.front(); q.pop();
            for(auto k : v[front]){
                if(--degree[k] == 0){
                    q.push(k);
                    A[k] = tmm;
                }
            }
        }
        tmm++;
    }
    for(int i=1;i<=n;i++) cout << A[i] << " ";


    return 0;
}