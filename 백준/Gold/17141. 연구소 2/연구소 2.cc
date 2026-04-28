#include <bits/stdc++.h>
using namespace std;

int n,c;
int A[50][50];
int total_space; // 퍼트려야 하는 공간의 수 
vector<pair<int,int>> v;

int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
            if(A[i][j] == 2){
                v.push_back({i,j});
                A[i][j] = 0;
                total_space++;
            }
            else if(A[i][j] == 0) total_space++;
        }
    }

    int size = v.size();
    vector<int> C(size);
    for(int i=0;i<size-c;i++) C[i] = 0;
    for(int i=size-c;i<size;i++) C[i] = 1;

    int ans = INT32_MAX;
    do{
        queue<pair<int,int>> q;
        int fill_space = 0;
        bool visited[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) visited[i][j] = false;
        for(int i=0;i<size;i++){
            if(C[i]){
                q.push(v[i]);
                visited[v[i].first][v[i].second] = true;
                fill_space++;
            }
        }
    
        int cnt = -1;
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                int frontx = q.front().first, fronty = q.front().second; q.pop();
                for(int j=0;j<4;j++){
                    int nx = frontx +  dx[j], ny = fronty + dy[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !A[nx][ny] && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                        fill_space++;
                    }
                }
            }
            cnt++;
        }

        if(fill_space == total_space) ans = min(ans, cnt);  // 모든 빈칸에 바이러스를 퍼트림.
        
    }while(next_permutation(C.begin(), C.end()));

    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
    return 0;
}