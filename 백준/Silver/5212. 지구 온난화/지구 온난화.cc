#include <bits/stdc++.h>
using namespace std;

int n,m;
char A[10][10];

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }
}

void remove_island(){
    int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    vector<pair<int,int>> remove_temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == '.') continue;
            int cnt = 0;
            for(int k=0;k<4;k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(A[nx][ny] == '.') cnt++;
                }
                else cnt++;
            }
            if(cnt >= 3) remove_temp.push_back({i,j});
        }
    }
    for(auto k : remove_temp) A[k.first][k.second] = '.';
}

void check_end_print(){
    int left = 10, right = 0, top = 10, bottom = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 'X'){
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }    
        }
    }

    for(int i=top;i<=bottom;i++){
        for(int j=left;j<=right;j++){
            cout << A[i][j];
        }
        cout << '\n';
    }
}

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << A[i][j];
        }
        cout << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    remove_island();
    //print();
    check_end_print();

    return 0;
}