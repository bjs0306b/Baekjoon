#include <iostream>
#include <algorithm>
using namespace std;

int a,b,arr[9];

void dfs(int n){
    if(n==b){
        for(int i=0;i<b;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=1;i<a+1;i++){
            arr[n]=i;
            dfs(n+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >>a>>b;
    dfs(0);
    
    return 0;
}