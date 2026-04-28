#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[101][101];
    memset(arr, 0, sizeof(int) * 101 * 101);
    for (int i = 0; i < 4; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int m = x1; m < x2; m++)
        {
            for (int n = y1; n < y2; n++)
            {
                arr[m][n]=1;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(arr[i][j] == 1) cnt++;
        }
    }
    cout << cnt;

    return 0;
}