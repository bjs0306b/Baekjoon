#include <bits/stdc++.h>
using namespace std;

bool apple[100][100];
bool body[100][100];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;
        apple[--x][--y] = true;
    }
    int b;
    cin >> b;
    deque<pair<int, char>> moves;
    for (int i = 0; i < b; i++)
    {
        int time;
        char direction;
        cin >> time >> direction;
        moves.push_back({time, direction});
    }

    int pos_x = 0, pos_y = 0;
    int current_direction = 0;
    int ans = 0;

    deque<pair<int,int>> body_queue; 
    body_queue.push_back({0,0});
    for (;;)
    {
        ans++;
        if (current_direction == 3)
        {
            if(--pos_x < 0) break;
        }
        else if (current_direction == 1)
        {
            if(++pos_x >= n) break;
        }
        else if (current_direction == 0)
        {
            if(++pos_y >= n) break;
        }
        else if (current_direction == 2)
        {
            if(--pos_y < 0) break;
        }

        if(body[pos_x][pos_y]) break;

        if(!apple[pos_x][pos_y]){
            body[body_queue.back().first][body_queue.back().second] = 0;
            body_queue.pop_back();
        }
        apple[pos_x][pos_y] = false;
        body_queue.push_front({pos_x, pos_y});
        body[pos_x][pos_y] = true;

        if(moves.front().first == ans){
            if(moves.front().second == 'D') current_direction = (current_direction + 1)%4;
            else current_direction = (current_direction + 3)%4;
            moves.pop_front();
        }
    }
    cout << ans;

    return 0;
}