#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y,status; // status 1 - 가로, 2 - 세로, 3 - 대각선
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    bool arr[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];

    queue<node> q;
    q.push({0,1,1});

    int ans = 0;

    while(!q.empty()){
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_status = q.front().status;
        q.pop();

        if(cur_x == n-1 && cur_y == n-1){
            ans++; continue;
        }

        if(cur_status == 1){
            if(cur_y < n-1 && arr[cur_x][cur_y + 1] == 0){
                q.push({cur_x, cur_y + 1, 1});
                if(cur_x < n-1 && arr[cur_x + 1][cur_y] == 0 && arr[cur_x + 1][cur_y + 1] == 0)
                    q.push({cur_x + 1, cur_y + 1, 3});
            }
        }

        else if(cur_status == 2){
            if(cur_x < n-1 && arr[cur_x + 1][cur_y] == 0){
                q.push({cur_x + 1, cur_y, 2});
                if(cur_y < n-1 && arr[cur_x][cur_y + 1] == 0 && arr[cur_x + 1][cur_y + 1] == 0)
                    q.push({cur_x + 1, cur_y + 1, 3});
            }
        }

        else{
            if(cur_y < n-1 && arr[cur_x][cur_y + 1] == 0){
                q.push({cur_x, cur_y + 1, 1});
                if(cur_x < n-1 && arr[cur_x + 1][cur_y] == 0 && arr[cur_x + 1][cur_y + 1] == 0)
                    q.push({cur_x + 1, cur_y + 1, 3});
            }
            if(cur_x < n-1 && arr[cur_x + 1][cur_y] == 0){
                q.push({cur_x + 1, cur_y, 2});
            }
        }
    }
    cout << ans;
    
    return 0;
}