#include <iostream>
#include <algorithm>
using namespace std;
int a,b,arr[9],visited[9];
void dfs(int n){
    if(n==b){
        int tf=1;
        for(int i=0;i<n-1;i++)
            if(arr[i] > arr[i+1])
                tf = 0;
        if(tf){
            for(int i=0;i<n;i++) cout << arr[i] << " ";
            cout << "\n";
        }
    }
    else{
        for(int i=1;i<a+1;i++){
            if(!visited[i]){
                visited[i] = 1;
                arr[n] = i;
                dfs(n+1);
                visited[i] = 0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >>a>>b;
    dfs(0);
    
    return 0;
}