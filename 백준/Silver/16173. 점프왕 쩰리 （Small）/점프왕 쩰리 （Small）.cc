#include<bits/stdc++.h>
using namespace std;
int n; 
int arr[3][3];
bool ans;
void func(int x, int y){
    if(arr[x][y]==0){return;}
    if(arr[x][y]==-1){ans = true; return;}
    int temp = arr[x][y];
    if(x+temp <n) func(x+temp,y);
    if(y+temp<n) func(x,y+temp);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    func(0,0);
    
    if(ans) cout << "HaruHaru";
    else cout << "Hing";
    return 0;
}