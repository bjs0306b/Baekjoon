#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int n,arr[9];
bool visited[9];

void dfs(int m){
    if(m == n){
        for(int i=0;i<n;i++) cout << arr[i] << " "; cout << "\n";
    }
    else{
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                arr[m] = i;
                visited[i] = true;
                dfs(m+1);
                visited[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    dfs(0);
    
    return 0;
}