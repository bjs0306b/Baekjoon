#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

vector<vector<int>> v;
bool isin(float x, float y){
    float tempx = x/2, tempy = y/2;
    cout << tempx << " " << tempy << "\n";
    for(auto k : v){
        if(tempx > k[0] && k[2] > tempx && tempy > k[1] && k[3] > tempy) return false;
    }
    return true;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<pair<int,int>> A[51][51];
    v = rectangle;
    bool visited[51][51]; memset(visited, false, sizeof(visited));
    for(auto k : rectangle){
        for(int i=k[0];i<k[2];i++){
            A[i][k[1]].push_back({i+1, k[1]});
            A[i][k[3]].push_back({i+1, k[3]});
        }
        for(int i=k[2];i>k[0];i--){
            A[i][k[1]].push_back({i-1, k[1]});
            A[i][k[3]].push_back({i-1, k[3]});
        }
        
        for(int i=k[1];i<k[3];i++){
            A[k[0]][i].push_back({k[0], i+1});
            A[k[2]][i].push_back({k[2], i+1});
        }
        for(int i=k[3];i>k[1];i--){
            A[k[0]][i].push_back({k[0], i-1});
            A[k[2]][i].push_back({k[2], i-1});
        }
    }
    
    queue<pair<int,int>> q;
    q.push({characterX, characterY});
    visited[characterX][characterY] = true;
    
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto f = q.front(); q.pop();
            //cout << f.first << " " << f.second << "\n";
            if(f.first == itemX && f.second == itemY) return ans;
            for(auto k : A[f.first][f.second]){
                int nx = k.first, ny = k.second;
                if(nx >= 0 && nx < 51 && ny >= 0 && ny < 51 && !visited[nx][ny] && isin(f.first + nx, f.second + ny)){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        ans++;
    }
    return -1;
}