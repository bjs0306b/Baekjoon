#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int a,b; 
string arr[10];
bool visited[10];
set<string> s;
vector<string> v;
void dfs(int n){
    if(n==b){
        string str;
        for(int i=0;i<b;i++){
            str += arr[i];
        }
        s.insert(str);
        return;
    }
    else{
        for(int i=0;i<a;i++){
            if(!visited[i]){
                arr[n] = v[i];
                visited[i] = true;
                dfs(n+1);
                visited[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++){
        string num; cin >> num; v.push_back(num);
    }
    dfs(0);
    cout << s.size();
    
    return 0;
}