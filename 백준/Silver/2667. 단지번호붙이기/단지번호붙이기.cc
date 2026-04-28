#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <set>
using namespace std;

bool arr[27][27];
int cc=0;

void dfs(int a, int b){
    arr[a][b]=false;
    cc++;
    if(arr[a-1][b]) dfs(a-1,b);
    if(arr[a+1][b]) dfs(a+1,b);
    if(arr[a][b-1]) dfs(a,b-1);
    if(arr[a][b+1]) dfs(a,b+1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >>n; 
    multiset<int> s;
    for(int i=0;i<27;i++) for(int j=0;j<27;j++) arr[i][j]=false;
    for(int i=1;i<n+1;i++){
        string str; cin >> str;
        for(int j=0;j<str.size();j++)
            if(str[j] == '1') arr[i][j+1] = true;
    }
    int cnt=0;
    for(int i=0;i<27;i++){
        for(int j=0;j<27;j++){
            if(arr[i][j]){
                cnt++; dfs(i,j);
                s.insert(cc); cc = 0;
            }
        }
    }
    cout << cnt << "\n";
    for(auto a : s) cout << a << "\n";

    
    return 0;
}