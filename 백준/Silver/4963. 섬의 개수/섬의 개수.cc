#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
int arr[53][53];

void dfs(int a, int b){
    arr[a][b]= 0;
    if(arr[a+1][b]) dfs(a+1,b);
    if(arr[a-1][b]) dfs(a-1,b);
    if(arr[a][b+1]) dfs(a,b+1);
    if(arr[a][b-1]) dfs(a,b-1);
    if(arr[a+1][b+1]) dfs(a+1,b+1);
    if(arr[a-1][b+1]) dfs(a-1,b+1);
    if(arr[a+1][b-1]) dfs(a+1,b-1);
    if(arr[a-1][b-1]) dfs(a-1,b-1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b; 
    for (;;)
    {
        cin >>a>>b;
        int cnt = 0;
        if (a == 0 && b == 0)
            break;
        for (int i = 1; i <= b; i++)
            for (int j = 1; j <= a; j++)
                cin >> arr[i][j];

        for (int i = 1; i <= b; i++){
            for (int j = 1; j <= a; j++){
                if(arr[i][j]){
                    dfs(i,j); cnt++;
                }
            }   
        }
        cout << cnt << "\n";
    }

    return 0;
}