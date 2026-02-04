#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y,key;
};

int n,m;
int x,y;
char A[50][50];
bool visited[50][50][1<<6]; // x,y를 000000 중 활성화된 키를 갖고 방문했음.

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
            if(A[i][j] == '0'){
                x = i, y = j;
                A[i][j] = '.';
            }
        }
    }
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int solve(){
    queue<node> q;
    q.push({x,y,0});
    visited[x][y][0] = true;

    int ret = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            node f = q.front();
            q.pop();

            for(int j=0;j<4;j++){
                int nx = f.x + dx[j], ny = f.y + dy[j];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] != '#' && !visited[nx][ny][f.key]){
                    visited[nx][ny][f.key] = true;
                    if(A[nx][ny] >= 'a' && A[nx][ny] <= 'f'){ // 열쇠
                        int num = A[nx][ny] - 'a';
                        int new_key = (1 << num) | f.key;
                        visited[nx][ny][new_key] = true;
                        q.push({nx,ny,new_key});
                    }
                    else if(A[nx][ny] >= 'A' && A[nx][ny] <= 'F'){ // 문
                        int num = A[nx][ny] - 'A';
                        int need_key = 1 << num;
                        if((f.key & need_key) == need_key) q.push({nx, ny, f.key});
                    }
                    else if(A[nx][ny] == '.'){ // 빈 공간
                        q.push({nx, ny, f.key});
                    }
                    else{ // 출구
                        return ret;
                    }
                }
            }
        }
        ret++;
    }
    return -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}