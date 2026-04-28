#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int arr[6];
vector<int> v;

void dfs(int n, int s){
    if(n==6){
        for(int i=0;i<6;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else{
        for(int i=s;i<v.size();i++){
            arr[n] = v[i];
            dfs(n+1, i+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    
    for(;;){
        cin >> n;
        if(n==0) break;
        for(int i=0;i<n;i++){int num; cin >> num; v.push_back(num);}
        dfs(0,0);
        v.clear();
        cout << "\n";
    }
    
    return 0;
}