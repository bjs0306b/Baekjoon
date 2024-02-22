#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int n, arr[1000][1000], white=0,blue=0;

void dfs(int a, int b, int s)
{
    bool check = true;
    int temp = arr[a][b];

    
    for (int i = a - a % s; i < a - a % s + s; i++)
    {
        for (int j = b - b % s; j < b - b % s + s; j++)
        {
            if (arr[i][j] != temp)
            {
                check = false;
                break;
            }
        }
        if(!check) break;
    }
    if (check)
    {
        dfs(a, b, 2 * s);
    }
    else
    {
        if(temp) blue++;
        else white++;

        s/=2;
        for (int i = a - a % s; i < a - a % s + s; i++)
        {
            for (int j = b - b % s; j < b - b % s + s; j++)
            {
                arr[i][j] = -1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int num; cin >> num; arr[i][j] = num;
        }
    }     

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != -1)
            {
                dfs(i, j, 1);
            }
        }
    }
    cout << white << "\n" << blue;
    return 0;
}