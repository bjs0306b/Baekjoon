#include <bits/stdc++.h>
using namespace std;

int n,m,d, cnt, ans;
int A[15][15], temp[15][15];
vector<int> v;

void attack(){
    // pick
    vector<pair<int,int>> kill_point;
    for(int i=0;i<m;i++){
        if(v[i] == 1){
            for(int j=1;j<=d;j++){
                int x = n-1, y = i + 1 - j;
                bool flag = false;

                if(x >= 0 && x < n && y >= 0 && y < m && A[x][y] == 1){
                    kill_point.push_back({x,y});
                    break;
                }
                for(int k=0;k<j-1;k++){
                    x--, y++;
                    if(x >= 0 && x < n && y >= 0 && y < m && A[x][y] == 1){
                        kill_point.push_back({x,y});
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
                for(int k=0;k<j-1;k++){
                    x++, y++;
                    if(x >= 0 && x < n && y >= 0 && y < m && A[x][y] == 1){
                        kill_point.push_back({x,y});
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
        }
    }


    // kill
    for(int i=0;i<kill_point.size();i++){
        int x = kill_point[i].first, y = kill_point[i].second;
        // cout << "x : " << x << ", y :" << y << "\n";
        if(A[x][y]){
            cnt++;
            A[x][y] = 0;
        }
    }
}

void down(){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<m;j++){
            A[i][j] = A[i-1][j];
        }
    }
    for(int i=0;i<m;i++) A[0][i] = 0;
}

void solve(){
    for(int i=0;i<m-3;i++) v.push_back(0);
    for(int i=m-3;i<m;i++) v.push_back(1);

    do{
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) A[i][j] = temp[i][j];

        // for(int i=0;i<m;i++){
        //     cout << v[i] << " ";
        // }
        // cout << "\n\n";

        cnt = 0;
        for(int i=0;i<n;i++){
            // cout << "I : " << i << "\n\n";
            attack(); // 궁수가 동시에 공격
            down(); // 적이 내려옴
        }
        // cout << "cnt : " << cnt << "\n\n";

        ans = max(ans, cnt);
    }while(next_permutation(v.begin(), v.end()));
    cout << ans;   
}

void input(){
    cin >> n >> m >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> temp[i][j];
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}