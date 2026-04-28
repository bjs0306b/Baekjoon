#include <iostream>
#include <algorithm>
using namespace std;
int a,b,arr[9];
void dfs(int n, int m){
    if(n==b){
        for(int i=0;i<b;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=m;i<a+1;i++){
            arr[n] = i;
            dfs(n+1, i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a>>b;
    dfs(0, 1);
    
    
    return 0;
}