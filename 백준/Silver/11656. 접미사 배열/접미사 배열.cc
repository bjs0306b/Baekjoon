#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str; cin >> str; set<string> s;
    for(int i=0;i<str.size();i++) s.insert(str.substr(i));
    for(auto a:s) cout << a <<"\n";
    
    
    return 0;
}