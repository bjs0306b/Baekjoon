#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int m,n,arr[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int start_i, start_j;
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if (num == 2){
                start_i = i;
                start_j = j;
                arr[i][j] = -2;
            }
            else if(num == 1)
                arr[i][j] = -1;
            else
                arr[i][j] = 0;
        }
    }
    deque<pair<int,int>> deq;
    deq.push_back({start_i, start_j});
    arr[start_i][start_j] = 0;
    while(!deq.empty()){
        int i = deq.front().first;
        int j = deq.front().second;
        deq.pop_front();
        if(i > 0 && arr[i-1][j] == -1){
            arr[i-1][j] = arr[i][j] + 1;
            deq.push_back({i-1,j});
        }
        if(i < m-1 && arr[i+1][j] == -1){
            arr[i+1][j] = arr[i][j] + 1;
            deq.push_back({i+1,j});
        }
        if(j > 0 && arr[i][j-1] == -1){
            arr[i][j-1] = arr[i][j] + 1;
            deq.push_back({i,j-1});
        }
        if(j < n-1 && arr[i][j+1] == -1){
            arr[i][j+1] = arr[i][j] + 1;
            deq.push_back({i,j+1});
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}