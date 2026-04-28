#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin>>a>>b;
    int cnt = 0;
    for(char c : a){
        if(find(b.begin(), b.end(), c) != b.end()) {cnt++;b.erase(find(b.begin(), b.end(), c));}
    }
    cout << a.size() - cnt + b.size();
    
    
    return 0;
}