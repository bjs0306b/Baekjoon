#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int a,b,arr[8];
set<vector<int>> s;
vector<int> v;
void dfs(int n, int st){
    if(n == b){
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        s.insert(temp);
    }
    else{
        for(int i=st;i<a;i++){                 
            arr[n] = v[i];
            dfs(n+1, i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    for(int i=0;i<a;i++){int num; cin >> num; v.push_back(num);}
    sort(v.begin(),v.end());
    dfs(0,0);
    for(auto k : s){
        for(auto l : k){
            cout << l << " ";
        }
        cout << "\n";
    }
    return 0;
}

