#include <bits/stdc++.h>
using namespace std;

char arr[10][10];

struct node
{
    int rx, ry, bx, by, before;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int redx, redy, bluex, bluey, goalx, goaly;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            char c;
            cin >> c;
            if (c == 'O')
            {
                goalx = i, goaly = j;
                arr[i][j] = '.';
            }
            else if (c == 'R')
            {
                redx = i, redy = j;
                arr[i][j] = '.';
            }
            else if (c == 'B')
            {
                bluex = i, bluey = j;
                arr[i][j] = '.';
            }
            else
                arr[i][j] = c;
        }
    }

    queue<node> q;
    q.push({redx, redy, bluex, bluey, 0});
    int cnt = 1;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node n = q.front();
            int rx = n.rx, ry = n.ry, bx = n.bx, by = n.by;

            q.pop();
            bool rf, bf;

            if(n.before != 2){
                // Move up
                rf = false, bf = false; // rf = red, bf = blue 가 구멍에 들어갔는가

                if (ry == by)
                {
                    if (rx < bx)
                    {
                        // Move red up first
                        while (arr[rx - 1][ry] != '#' && (rx - 1 != bx || ry != by))
                        {
                            rx--;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        // Move blue up
                        while (arr[bx - 1][by] != '#' && (bx - 1 != rx || by != ry))
                        {
                            bx--;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,1});
                    }
                    else
                    {
                        // Move blue up first
                        while (arr[bx - 1][by] != '#' && (bx - 1 != rx || by != ry))
                        {
                            bx--;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        // Move red up
                        while (arr[rx - 1][ry] != '#' && (rx - 1 != bx || ry != by))
                        {
                            rx--;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,1});
                    }
                }
                else
                {
                    while (arr[rx - 1][ry] != '#' && (rx - 1 != bx || ry != by))
                    {
                        rx--;
                        if (rx == goalx && ry == goaly){
                            rf = true;
                            rx = -1, ry = -1;
                            break;
                        }
                        
                    }
                    while (arr[bx - 1][by] != '#' && (bx - 1 != rx || by != ry))
                    {
                        bx--;
                        if (bx == goalx && by == goaly){
                            bf = true;
                            bx = -1, by = -1;
                            break;
                        }
                    }
                    if (rf && !bf)
                    {
                        cout << cnt;
                        return 0;
                    }
                    if (!bf)
                        q.push({rx, ry, bx, by,1});
                }
            }


            if(n.before != 1){
                // Reset positions for the next direction
                rx = n.rx, ry = n.ry, bx = n.bx, by = n.by;

                // Move down
                rf = false, bf = false;
                if (ry == by)
                {
                    if (rx > bx)
                    {
                        // Move red down first
                        while (arr[rx + 1][ry] != '#' && (rx + 1 != bx || ry != by))
                        {
                            rx++;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        // Move blue down
                        while (arr[bx + 1][by] != '#' && (bx + 1 != rx || by != ry))
                        {
                            bx++;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,2});
                    }
                    else
                    {
                        // Move blue down first
                        while (arr[bx + 1][by] != '#' && (bx + 1 != rx || by != ry))
                        {
                            bx++;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        // Move red down
                        while (arr[rx + 1][ry] != '#' && (rx + 1 != bx || ry != by))
                        {
                            rx++;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,2});
                    }
                }
                else
                {
                    while (arr[rx + 1][ry] != '#' && (rx + 1 != bx || ry != by))
                    {
                        rx++;
                        if (rx == goalx && ry == goaly){
                            rf = true;
                            rx = -1, ry = -1;
                            break;
                        }
                        
                    }
                    while (arr[bx + 1][by] != '#' && (bx + 1 != rx || by != ry))
                    {
                        bx++;
                        if (bx == goalx && by == goaly){
                            bf = true;
                            bx = -1, by = -1;
                            break;
                        }
                    }
                    if (rf && !bf)
                    {
                        cout << cnt;
                        return 0;
                    }
                    if (!bf)
                        q.push({rx, ry, bx, by,2});
                }
            }
            if(n.before != 4){
                // Move right
                rx = n.rx, ry = n.ry, bx = n.bx, by = n.by;
                rf = false, bf = false;
                if (rx == bx)
                {
                    if (ry > by)
                    {
                        // Move red right first
                        while (arr[rx][ry + 1] != '#' && (rx != bx || ry + 1 != by))
                        {
                            ry++;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        // Move blue right
                        while (arr[bx][by + 1] != '#' && (bx != rx || by + 1 != ry))
                        {
                            by++;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,3});
                    }
                    else
                    {
                        // Move blue right first
                        while (arr[bx][by + 1] != '#' && (bx != rx || by + 1 != ry))
                        {
                            by++;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        // Move red right
                        while (arr[rx][ry + 1] != '#' && (rx != bx || ry + 1 != by))
                        {
                            ry++;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,3});
                    }
                }
                else
                {
                    while (arr[rx][ry + 1] != '#' && (rx != bx || ry + 1 != by))
                    {
                        ry++;
                        if (rx == goalx && ry == goaly){
                            rf = true;
                            rx = -1, ry = -1;
                            break;
                        }
                        
                    }
                    while (arr[bx][by + 1] != '#' && (bx != rx || by + 1 != ry))
                    {
                        by++;
                        if (bx == goalx && by == goaly){
                            bf = true;
                            bx = -1, by = -1;
                            break;
                        }
                    }
                    if (rf && !bf)
                    {
                        cout << cnt;
                        return 0;
                    }
                    if (!bf)
                        q.push({rx, ry, bx, by,3});
                }
            }
            if(n.before != 3){
                // Move left
                rx = n.rx, ry = n.ry, bx = n.bx, by = n.by;
                rf = false, bf = false;
                if (rx == bx)
                {
                    if (ry < by)
                    {
                        // Move red left first
                        while (arr[rx][ry - 1] != '#' && ry - 1 != by)
                        {
                            ry--;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        // Move blue left
                        while (arr[bx][by - 1] != '#' && (bx != rx || by - 1 != ry))
                        {
                            by--;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,4});
                    }
                    else
                    {
                        // Move blue left first
                        while (arr[bx][by - 1] != '#' && (bx != rx || by - 1 != ry))
                        {
                            by--;
                            if (bx == goalx && by == goaly){
                                bf = true;
                                bx = -1, by = -1;
                                break;
                            }

                        }
                        // Move red left
                        while (arr[rx][ry - 1] != '#' && (rx != bx || ry - 1 != by))
                        {
                            ry--;
                            if (rx == goalx && ry == goaly){
                                rf = true;
                                rx = -1, ry = -1;
                                break;
                            }
                            
                        }
                        if (rf && !bf)
                        {
                            cout << cnt;
                            return 0;
                        }
                        if (!bf)
                            q.push({rx, ry, bx, by,4});
                    }
                }
                else
                {
                    while (arr[rx][ry - 1] != '#' && (rx != bx || ry - 1 != by))
                    {
                        ry--;
                        if (rx == goalx && ry == goaly){
                            rf = true;
                            rx = -1, ry = -1;
                            break;
                        }
                        
                    }
                    while (arr[bx][by - 1] != '#' && (bx != rx || by - 1 != ry))
                    {
                        by--;
                        if (bx == goalx && by == goaly){
                            bf = true;
                            bx = -1, by = -1;
                            break;
                        }
                    }
                    if (rf && !bf)
                    {
                        cout << cnt;
                        return 0;
                    }
                    if (!bf)
                        q.push({rx, ry, bx, by,4});
                }
            }
        }
        cnt++;
        if(cnt == 11) break;
    }

    cout << -1; 
    return 0;
}
