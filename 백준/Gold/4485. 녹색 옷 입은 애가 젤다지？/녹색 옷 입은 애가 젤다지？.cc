#include <bits/stdc++.h>    
using namespace std;
int n , ans;
int A[125][125];
int mn[125][125];

int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;;i++){
        cin >> n; 
        if(!n) break;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){cin >> A[i][j]; mn[i][j] = INT32_MAX;}
        mn[0][0] = A[0][0];
        
        queue<pair<int,int>> q; q.push({0,0});
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int x = f.first, y = f.second;
            for(int i=0;i<4;i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    if(mn[nx][ny] > mn[x][y] + A[nx][ny]){
                        mn[nx][ny] = mn[x][y] + A[nx][ny];
                        q.push({nx, ny});
                    }
                }
            }
        }

        cout << "Problem " << i << ": " << mn[n-1][n-1] << "\n";
    }   
    return 0;
}