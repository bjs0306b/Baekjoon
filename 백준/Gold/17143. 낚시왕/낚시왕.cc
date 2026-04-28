#include <bits/stdc++.h>
using namespace std;

struct shark{
    int s,d,z;
};
int R,C,M;
int ans;
shark A[101][101];

void input(){
    cin >> R >> C >> M;
    for(int i=0;i<M;i++){
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        d--;
        A[r][c] = {s,d,z};
    }
}

void catch_shark(int n){
    for(int i=1;i<=R;i++){
        if(A[i][n].z > 0){
            ans += A[i][n].z;
            A[i][n] = {0,0,0};
            break;
        }
    }
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
void move(){
    shark temp[101][101];
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            temp[i][j] = {0,0,0};
        }
    }

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            shark sh = A[i][j];
            // 상어 존재
            if(sh.z > 0){   
                int nx = i, ny = j;
                int size = sh.s;
                if(sh.d > 1){ // 2,3 -> 좌우
                    size = sh.s % (2*(C-1));
                }
                else size = sh.s % (2*(R-1)); // 0,1 -> 상하

                for(int k=0;k<size;k++){
                    // 방향 바꾸기
                    if(sh.d == 0 && nx == 1) sh.d++;
                    else if(sh.d == 1 && nx == R) sh.d--;
                    else if(sh.d == 2 && ny == C) sh.d++;
                    else if(sh.d == 3 && ny == 1) sh.d--;

                    // 이동
                    nx += dx[sh.d], ny += dy[sh.d];   
                }
                
                // 크기 큰 상어가 잡아 먹음.
                if(temp[nx][ny].z < sh.z){
                    temp[nx][ny] = sh;
                }
            }
        }
    }

    // 이동 덮어쓰기
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            A[i][j] = temp[i][j];
        }
    }
}

void print(){
    cout << "\n";
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cout << A[i][j].z << " ";
        }
        cout << "\n";
    }
}

void solve(){
    //print();
    for(int i=1;i<=C;i++){
        catch_shark(i);
        move();
        //print();
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    solve();
}