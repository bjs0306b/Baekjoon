#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[50][50];
vector<pair<int,int>> virus;
int zero_cnt;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> A[i][j];
            if(A[i][j] == 2){
                virus.push_back({i,j});
            }
            if(A[i][j] == 0) zero_cnt++;
        }
    }
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void solve(){
    if(zero_cnt == 0){
        cout << 0;
        return;
    }
    int ans = INT32_MAX;
    int size = virus.size();
    vector<int> c(size, 0);
    for(int i=size-1;i>size-1-m;i--) c[i] = 1;

    bool visited[n][n]; 
       
    do{
        queue<pair<int,int>> q;
        for(int i=0;i<size;i++) if(c[i]) q.push(virus[i]);

        for(int i=0;i<n;i++) for(int j=0;j<n;j++) visited[i][j] = false;
        
        int cnt = 0;
        int zero_cnt_temp = zero_cnt;

        while(!q.empty()){       
            int size = q.size();
            for(int i=0;i<size;i++){
                auto k = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nx = k.first + dx[j], ny = k.second + dy[j];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && A[nx][ny] != 1){
                        if(A[nx][ny] == 0){
                            zero_cnt_temp--;
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                        else if(A[nx][ny] == 2){
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }   

            cnt++;
            if(zero_cnt_temp == 0) break;
        }

        // cout << "now permutation is : ";
        // for(int i=0;i<size;i++) cout << c[i] << " ";
        // cout << "\n zero_cnt_temp is : " << zero_cnt_temp << "\n";
        // cout << "cnt is : " << cnt << "\n";
 
        if(zero_cnt_temp == 0) ans = min(ans, cnt); 
    }while(next_permutation(c.begin(), c.end()));

    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}