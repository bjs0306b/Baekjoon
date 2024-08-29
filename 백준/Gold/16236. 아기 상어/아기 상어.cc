#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n][n];
    int pos_x, pos_y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if (num == 9)
            {
                arr[i][j] = 0;
                pos_x = i, pos_y = j;
            }
            else
            {
                arr[i][j] = num;
            }
        }
    }
    int size = 2;
    int eat = 0;
    int ans = 0;

    while (true)
    {
        queue<pair<int, int>> q;
        q.push({pos_x, pos_y});
        bool visited[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = 0;
        visited[pos_x][pos_y] = true;

        vector<pair<int, int>> fishes; // 먹을 수 있는 물고기 위치 저장
        int cnt = 0;
        bool found = false;

        while (!q.empty())
        {
            int size_q = q.size();
            cnt++;
            for (int i = 0; i < size_q; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                // 상, 좌, 우, 하 순서로 탐색
                int dx[] = {-1, 0, 0, 1};
                int dy[] = {0, -1, 1, 0};

                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] <= size)
                    {
                        visited[nx][ny] = true;
                        if (arr[nx][ny] > 0 && arr[nx][ny] < size)
                        {
                            fishes.push_back({nx, ny});
                            found = true;
                        }
                        q.push({nx, ny});
                    }
                }
            }
            if (found)
                break; // 가장 가까운 거리의 물고기들을 모두 찾음
        }

        if (fishes.empty())
            break; // 더 이상 먹을 수 있는 물고기가 없는 경우 종료

        // 물고기 정렬: 행(위쪽) -> 열(왼쪽) 우선순위로 정렬
        sort(fishes.begin(), fishes.end());

        // 가장 가까운 물고기를 먹는다
        int nx = fishes[0].first;
        int ny = fishes[0].second;

        pos_x = nx;
        pos_y = ny;
        arr[pos_x][pos_y] = 0; // 먹은 물고기 제거
        ans += cnt;
        eat++;

        if (eat == size)
        {
            size++;
            eat = 0;
        }
    }

    cout << ans;
    return 0;
}
