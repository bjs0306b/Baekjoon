#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    int arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    vector<int> dice(6, 0);
    dice[1] = arr[x][y];
    while (k--)
    {
        int num;
        cin >> num;
        num--;

        int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

        if (x + dx[num] >= 0 && x + dx[num] < n && y + dy[num] >= 0 && y + dy[num] < m)
        {
            x += dx[num], y += dy[num];

            if(num == 0){
                int temp = dice[5];
                dice[5] = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[1];
                dice[1] = temp;
            }
            else if(num == 1){
                int temp = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[0];
                dice[0] = temp;
            }
            else if(num == 2){
                int temp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[1];
                dice[1] = dice[3];
                dice[3] = temp;
            }
            else if(num == 3){
                int temp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[1];
                dice[1] = dice[2];
                dice[2] = temp;
            }

            if(arr[x][y] == 0){
                arr[x][y] = dice[1];
            }
            else{
                dice[1] = arr[x][y];
                arr[x][y] = 0;
            }
            
            cout << dice[0] << "\n";
        }
    }

    return 0;
}