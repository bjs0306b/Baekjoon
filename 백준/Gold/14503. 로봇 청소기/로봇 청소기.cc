#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    bool arr[n][m], cleaned[n][m];
    memset(cleaned, 0, sizeof(cleaned));
    int x,y,face; cin >> x >> y >> face;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> arr[i][j];


    int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
    int cnt = 0;
    for(;;){
        if(!cleaned[x][y]){cleaned[x][y] = 1; cnt++;} // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.

        int i;
        for(i=3;i>=0;i--){
            if(x+dx[(face+i)%4] >= 0 && x+dx[(face+i)%4] < n && y+dy[(face+i)%4] >= 0 && y+dy[(face+i)%4] < m && arr[x+dx[(face+i)%4]][y+dy[(face+i)%4]] == 0 && cleaned[x+dx[(face+i)%4]][y+dy[(face+i)%4]] == 0){
                face = (face+i)%4;
                break;
            }
        }
        if(i == -1) // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        {
            if(x+dx[(face+2)%4] >= 0 && x+dx[(face+2)%4] < n && y+dy[(face+2)%4] >= 0 && y+dy[(face+2)%4] < m && arr[x+dx[(face+2)%4]][y+dy[(face+2)%4]] == 0){ 
                //바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
                x += dx[(face+2)%4];
                y += dy[(face+2)%4];
                continue;
            }
            else break; // 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
        }
        else // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        {
            x += dx[face], y += dy[face]; // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        }
        //cout << x << " " << y << "\n";
    }
    cout << cnt;

    return 0;
}