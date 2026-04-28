#include <bits/stdc++.h>
using namespace std;

bool A[1000][1000]; // - 좌표도 가능하니 (0,0)을 (500,500)으로 두고 시작.

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
void paint(int x, int y, int d, int g)
{
    vector<int> v;
    v.push_back(d);
    if(g) v.push_back((d + 1) % 4);
    bool cw = true; // 시계 방향 여부.
    g--;
    while (g > 0)
    {
        int size = v.size();
        vector<int> temp;
        for (int i = 1; i < size; i += 2) // 2번째 추출.
            temp.push_back(v[i]);
        reverse(temp.begin(), temp.end());    // 좌우반전
        for (int i = 0; i < temp.size(); i++) // CCW 회전
            temp[i] = (temp[i] + 1) % 4;

        for (int i = 0; i < temp.size(); i++)
        {
            v.push_back(temp[i]);
            if (cw){
                v.push_back((temp[i]+3)%4);
                cw = !cw;
            } 
            else{
                v.push_back((temp[i]+1)%4);
                cw = !cw;
            }
        }
        g--;
    }

    A[x][y] = true;
    for(int i=0;i<v.size();i++){
        int d = v[i];
        x += dx[d], y += dy[d];
        A[x][y] = true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        int x,y,d,g; cin >> x >> y >> d >> g;
        paint(y+500, x+500, d, g);
    }

    // for(int i=500;i<507;i++){
    //     for(int j=500;j<507;j++){
    //         cout << A[i][j];
    //     }
    //     cout << "\n";
    // }

    int ans = 0;
    for(int i=0;i<999;i++){
        for(int j=0;j<999;j++){
            if(A[i][j] && A[i+1][j] && A[i][j+1] && A[i+1][j+1]) ans++;
        }
    }
    cout << ans;

    return 0;
}