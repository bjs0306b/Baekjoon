#include<bits/stdc++.h>
using namespace std;

struct node{
    int z,y,x;
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x,y,z;
    cin >> x >> y >> z;
    int arr[z][y][x];
    
    queue<node> q;
    int cnt = 0;
    for(int i=0;i<z;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<x;k++){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                     q.push({i,j,k});
                }
                else if(arr[i][j][k] == 0) cnt++;
            }
        }
    } 

    int ans = -1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){    
            node n = q.front(); q.pop();

            if(n.x + 1 < x && arr[n.z][n.y][n.x+1]==0){q.push({n.z, n.y, n.x+1}); arr[n.z][n.y][n.x+1]=1; cnt--;}
            if(n.y + 1 < y && arr[n.z][n.y+1][n.x]==0) {q.push({n.z, n.y+1, n.x});arr[n.z][n.y+1][n.x]=1; cnt--;}
            if(n.z + 1 < z && arr[n.z+1][n.y][n.x]==0) {q.push({n.z+1, n.y, n.x});arr[n.z+1][n.y][n.x]=1; cnt--;}
            if(n.x > 0 && arr[n.z][n.y][n.x-1]==0) {q.push({n.z, n.y, n.x-1});arr[n.z][n.y][n.x-1]=1; cnt--;}
            if(n.y > 0 && arr[n.z][n.y-1][n.x]==0) {q.push({n.z, n.y-1, n.x});arr[n.z][n.y-1][n.x]=1; cnt--;}
            if(n.z > 0 && arr[n.z-1][n.y][n.x]==0) {q.push({n.z-1, n.y, n.x});arr[n.z-1][n.y][n.x]=1; cnt--;}
        }
        ans++;
    }

    if(cnt == 0) cout << ans;
    else cout << -1;

    // for(int i=0;i<z;i++){
    //     for(int j=0;j<y;j++){
    //         for(int k=0;k<x;k++){
    //             cout << arr[i][j][k] << " ";
    //         }
    //         cout << '\n';
    //     }
    // } 

    
    return 0;
}