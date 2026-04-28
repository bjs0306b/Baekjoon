#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<string> v;
    while(n--){
        string s; cin >> s; v.push_back(s);
    }
    for(auto a : v){
        string b = a; reverse(b.begin(), b.end());
        if(find(v.begin(), v.end(), b) != v.end()){
            cout << a.size() << " " << a[a.size()/2];
            return 0;
        }
    }
    
    return 0;
}