#include <bits/stdc++.h>
using namespace std;

int n,k, A[12][12]; 
bool finish;
deque<int> dq[12][12];
vector<pair<int,int>> pos;
vector<int> dir;

void input(){
    cin >> n >> k;
    pos.resize(k);
    dir.resize(k);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
    for(int i=0;i<k;i++){
        cin >> pos[i].first >> pos[i].second >> dir[i];
        pos[i].first--; 
        pos[i].second--;
        dq[pos[i].first][pos[i].second].push_back(i);
    }
}

int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
void move(int num, bool pre_is_blue){
    if(finish) return;
    int x = pos[num].first, y = pos[num].second;
    int d = dir[num] - 1;

    int nx = x + dx[d], ny = y + dy[d];
    // 파랑 or 벗어남
    if(!(nx >= 0 && nx < n && ny >= 0 && ny < n) || A[nx][ny] == 2){
        if(pre_is_blue) return; // 이전도 블루  
        
        if(dir[num] % 2) dir[num]++; // 방향 바꾸기
        else dir[num]--;
        move(num, true);
    }
    // 빨강
    else if(A[nx][ny] == 1){
        deque<int> dq2;
        for(int i=0;i<dq[x][y].size();i++){
            if(dq[x][y][i] == num){
                int temp = i;
                int size = dq[x][y].size();
                while(temp != size){
                    dq2.push_back(dq[x][y][temp]);
                    temp++;
                }
                for(int j=i;j<size;j++){
                    dq[x][y].pop_back();
                }

                break;
            }
        }     
        pos[num] = {nx, ny};

        reverse(dq2.begin(), dq2.end());
        for(int i=0;i<dq2.size();i++){
            pos[dq2[i]] = {nx,ny};
            dq[nx][ny].push_back(dq2[i]);
        }
        if(dq[nx][ny].size() > 3) finish = true;
    }
    // 흰
    else if(A[nx][ny] == 0){
        for(int i=0;i<dq[x][y].size();i++){
            if(dq[x][y][i] == num){
                int temp = i;
                int size = dq[x][y].size();
                while(temp != size){
                    dq[nx][ny].push_back(dq[x][y][temp]);
                    pos[dq[x][y][temp]] = {nx,ny};
                    temp++;
                }
                for(int j=i;j<size;j++){
                    dq[x][y].pop_back();
                }

                break;
            }
        }
        if(dq[nx][ny].size() > 3) finish = true;
    }
}

void print(){
    cout << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dq[i][j].size();
        }
        cout << "\n";
    }
}   

int solve(){
    for(int i=1;i<=1000;i++){
        //cout << "\n" << i << "\n";
        for(int j=0;j<k;j++){
            move(j, false);
            //print();
        }
        if(finish) return i;
    }
    return -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}