#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int arr[100][100];
bool arrive[100][100];

void dfs(int a, int b){
    arrive[a][b] = false;
    if(arrive[a+1][b] && a+1 < 100) dfs(a+1,b);
    if(arrive[a][b+1] && b+1 < 100) dfs(a,b+1);
    if(arrive[a-1][b] && a-1>=0) dfs(a-1,b);
    if(arrive[a][b-1] && b-1>=0) dfs(a,b-1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, mx = 0, mn = 101, ans = 1; cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {int num; cin >> num; arr[i][j] = num; mx = max(mx,num); mn = min(mn,num);}
    for(int i=mn;i<=mx;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(arr[j][k] > i) arrive[j][k] = true;
                else arrive[j][k] = false;
            }
        }
        int cnt = 0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(arrive[j][k]){dfs(j,k);cnt++;}
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    
    return 0;
}