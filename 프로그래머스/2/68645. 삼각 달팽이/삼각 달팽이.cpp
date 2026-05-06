#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    int A[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i][j] = 0;
    int dx[] = {1,0,-1}, dy[] = {0,1,-1};
    int cur_x = 0, cur_y = 0, cur_dir = 0;
    for(int i=1;i<=n*(n+1)/2;i++){
        A[cur_x][cur_y] = i;
        int nx, ny;
        nx = cur_x + dx[cur_dir], ny = cur_y + dy[cur_dir];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] == 0){
            cur_x = nx, cur_y = ny;
        }
        else{
            cur_dir = (cur_dir + 1) % 3;
            nx = cur_x + dx[cur_dir], ny = cur_y + dy[cur_dir];
            cur_x = nx, cur_y = ny;
        }
    }
    vector<int> ret;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            ret.push_back(A[i][j]);
        }
    }
    return ret;
}