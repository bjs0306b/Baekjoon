#include <bits/stdc++.h>
using namespace std;

int n,m;
char A[100][100];
bool visited[100][100];

struct node{
    int x,y,s;
};

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }
}

int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int check(int x, int y){
    for(int i=1;;i++){
        int cnt = 0;
        for(int j=0;j<4;j++){
            int nx = x + i * dx[j], ny = y + i * dy[j];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == '*'){
                cnt++;
                continue;
            }
            return i-1;
        }
        visited[x][y] = true;
        for(int j=0;j<4;j++){
            int nx = x + i * dx[j], ny = y + i * dy[j];
            visited[nx][ny] = true;
        }
    }
}

void solve(){
    
    vector<node> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == '*'){
                int temp = check(i,j);
                if(temp){
                    for(int k=temp;k>=1;k--) v.push_back({i+1, j+1, k});
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == '*' && !visited[i][j]){
                cout << -1;
                return;
            }
        }
    }

    int size = v.size();
    if(size){
        cout << size << "\n";
        for(int i=0;i<size;i++){
            cout << v[i].x << " " << v[i].y << " " << v[i].s << "\n";
        }
    }
    else cout << -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}