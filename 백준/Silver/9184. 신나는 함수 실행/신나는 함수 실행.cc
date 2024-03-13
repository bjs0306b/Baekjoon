#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int arr[21][21][21];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;

    
    arr[0][0][0] = 1;
    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            for(int k=0;k<21;k++)
                if(i == 0 || j == 0 || k == 0)
                    arr[i][j][k] = 1;
    for(int i=1;i<21;i++)
        for(int j=1;j<21;j++)
            for(int k=1;k<21;k++)
            {
                if(i < j && j < k)
                    arr[i][j][k] = arr[i][j][k-1] + arr[i][j-1][k-1] - arr[i][j-1][k];
                else
                    arr[i][j][k] = arr[i-1][j][k] + arr[i-1][j-1][k] + arr[i-1][j][k-1] - arr[i-1][j-1][k-1];
            }
        
    for (;;)
    {
        int ans;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        if(a <= 0 || b <= 0 || c <= 0)
            ans = 1;
        else if (a > 20 || b > 20 || c > 20)
            ans = arr[20][20][20];
        else ans = arr[a][b][c];
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << "\n";
    }

    return 0;
}