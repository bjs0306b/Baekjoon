#include <bits/stdc++.h>
using namespace std;

int n,m; 
int cnt = 1;
int A[300][300];

int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
void melt(){
    int melt_cnt[n][m]; for(int i=0;i<n;i++) for(int j=0;j<m;j++) melt_cnt[i][j] = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == 0) melt_cnt[i][j]++;
                }
            }
            
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            A[i][j] -= melt_cnt[i][j];
            if(A[i][j] < 0) A[i][j] = 0;
        }
    }
}

bool visited[300][300];

void dfs(int x, int y){
    for(int k=0;k<4;k++){
        int nx = x + dx[k], ny = y + dy[k];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs(nx,ny);
        } 
    }
}

bool is_separate(){


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }

    bool check = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){      
            if(!visited[i][j] && A[i][j]){

                if(check) return true;
                else check = true;

                visited[i][j] = true;
                dfs(i,j);
            }
        }
    }
    return false;
}

int start_simulate(){
    for(;;){
        melt();

        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]){
                    flag = true;
                }
            }
        }
        if(!flag) return 0;

        if(is_separate()) return cnt;
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }

    cout << start_simulate();

    return 0;
}