#include<bits/stdc++.h>
using namespace std;
int a,b;
set<int> s;

void func(int n, vector<int> v){
    if(n == b){
        for(int i=0;i<b;i++) cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for(auto i : s){
        v.push_back(i);
        func(n+1,v);
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a>>b;
    for(int i=0;i<a;i++){
        int x; cin >> x;
        s.insert(x);
    }
    func(0,vector<int>());
    
    
    return 0;
}