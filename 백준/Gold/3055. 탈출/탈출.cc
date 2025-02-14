#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int r,c; cin >> r >> c;
    int target_x, target_y;
    vector<vector<bool>> water(r, vector<bool>(c, false)), stone(r, vector<bool>(c, false)), visited(r, vector<bool>(c, false));
    queue<pair<int,int>> water_q, pos_q;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c; cin >> c;
            if(c == 'D'){
                target_x = i;
                target_y = j;
            }
            else if(c == 'S'){
                pos_q.push({i,j});
                visited[i][j] = true;
            }
            else if(c == '*'){
                water[i][j] = true;
                water_q.push({i,j});
            }
            else if(c == 'X') stone[i][j] = true;
        }
    }
    
    int ans = 0;
    while(!pos_q.empty()){
        
        ans++;

        // 물
        int size = water_q.size();
        for(int i=0;i<size;i++){
            int x = water_q.front().first, y = water_q.front().second;
            water_q.pop();
            for(int j=0;j<4;j++){
                int nx = x + dx[j], ny = y + dy[j];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && !stone[nx][ny] && !water[nx][ny] && !(nx == target_x && ny == target_y)){
                    water_q.push({nx,ny});
                    water[nx][ny] = true;
                }
            }
        }

        // cout << ans << "\n";
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout << water[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // 이동

        size = pos_q.size();
        for(int i=0;i<size;i++){
            int x = pos_q.front().first, y = pos_q.front().second;
            pos_q.pop();
            for(int j=0;j<4;j++){
                int nx = x + dx[j], ny = y + dy[j];
                if(nx >= 0 && nx < r && ny >= 0 && ny < c && !stone[nx][ny] && !water[nx][ny] && !visited[nx][ny]){

                    if(nx == target_x && ny == target_y){
                        cout << ans;
                        return 0;
                    }
                    pos_q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    cout << "KAKTUS";
    return 0;
}