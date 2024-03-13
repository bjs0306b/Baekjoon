#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int arr[50][50],a,b,max_size=0;

void dfs(int m, int n, int size){
    if(m+size < a && n+size < b){
        if(arr[m][n]==arr[m+size][n] && arr[m][n]==arr[m][n+size] && arr[m][n]==arr[m+size][n+size]){
            max_size = max(max_size,size);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++){
        string s; cin >> s;
        for(int j=0;j<b;j++){
            arr[i][j] = s[j]-'0';
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=1;k<min(a,b);k++){
                if(k > max_size) dfs(i,j,k);
            }
        }
    }
    cout << pow(max_size+1,2);
    return 0;
}