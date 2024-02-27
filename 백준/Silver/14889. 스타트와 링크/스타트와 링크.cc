#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int arr[20][20];
int n, mn = INT32_MAX;
int t1[20],t2[20];
bool visited[20];
void dfs(int a, int s){
    if(a == n/2){
        int j = 0, sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++){
            if(find(t1,t1+n/2,i) == t1+n/2) t2[j++] = i;
        }

        // for(int i=0;i<n/2;i++) cout << t2[i] << " ";
        // cout << "\n";

        for(int i=0;i<n/2-1;i++){
            for(int j=i+1;j<n/2;j++){
                sum1 += (arr[t1[i]][t1[j]]+arr[t1[j]][t1[i]]);
            }
        }
        for(int i=0;i<n/2-1;i++){
            for(int j=i+1;j<n/2;j++){
                sum2 += (arr[t2[i]][t2[j]]+arr[t2[j]][t2[i]]);
            }
        }
        int ans = abs(sum1-sum2);
        mn = min(mn,ans);
    }
    else{
        for(int i = s; i < n; i++){
            if(!visited[i]){
                t1[a] = i;
                visited[i] = true;
                dfs(a+1, i+1);
                visited[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];
    visited[0] = true;
    t1[0] = 0;
    dfs(1,1);
    cout << mn;
    return 0;
}