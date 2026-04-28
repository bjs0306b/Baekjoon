#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int a,b, arr[9];
set<vector<int>> s;
vector<int> v;
bool visited[9];
void dfs(int num){
    if(num == b){
        vector<int> temp;
        for(int i=0;i<b;i++){
            temp.push_back(arr[i]);
        }
        s.insert(temp);
    }
    else{
        for(int i=0;i<a;i++){
            if(!visited[i]){
                arr[num] = v[i];
                visited[i] = true;
                dfs(num+1);
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++){int num; cin >> num; v.push_back(num);}
    dfs(0);
    for(auto k : s){
        for(auto l : k) cout << l << ' ';
        cout << '\n';
    }
    return 0;
}