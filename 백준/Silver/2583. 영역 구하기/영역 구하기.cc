#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
bool arr[101][101];
int aa,bb,cc; 
int cnt2;
void dfs(int a, int b){
    arr[a][b] = 1;
    cnt2++;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int x = a + dx[i];
        int y = b + dy[i];
        if(x < 0 || y < 0 || x >= aa || y >= bb) continue;
        if(!arr[x][y]) dfs(x,y);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> bb >> aa >> cc;
    for(int i=0;i<cc;i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        for(int j=x1;j<x2;j++){
            for(int k=y1;k<y2;k++){
                arr[j][k] = 1;
            }
        }
    }
    int ans = 0;
    multiset<int> s;
    for(int i=0;i<aa;i++){
        for(int j=0;j<bb;j++){
            if(!arr[i][j]) {dfs(i,j); ans++; s.insert(cnt2); cnt2 = 0;}
        }
    }
    cout << ans << "\n";
    for(auto i : s) cout << i << " ";
    return 0;
}