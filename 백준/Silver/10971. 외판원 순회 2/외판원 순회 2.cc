#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int n, mn_dis = 10000000,arr[10][10], arr2[10];;
bool visited[10];

void dfs(int s, int e, int ss, int cnt, int sum){
    if(cnt == n){
        if(arr[e][ss]) mn_dis = min(mn_dis, sum + arr[e][ss]);
    }
    else{
        for(int i=0;i<n;i++){
            if(!visited[i] && arr[e][i]){
                visited[i] = true;
                if(sum+arr[e][i] < mn_dis) dfs(e, i, ss, cnt+1, sum+arr[e][i]);
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]){
                visited[i] = true;
                visited[j] = true;
                dfs(i,j,i,2, arr[i][j]);
                memset(visited, 0, sizeof(visited));
            }
        }
    }
    cout << mn_dis;
    
    return 0;
}