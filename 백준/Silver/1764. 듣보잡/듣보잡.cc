#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >>a>>b;
    string str[a];
    set<string> se;
    for(int i=0;i<a;i++) cin >> str[i];
    sort(str, str+a);
    for(int i=0;i<b;i++){
        string s; cin >> s;
        if(binary_search(str, str+a, s)) se.insert(s);
    }
    cout << se.size() <<"\n";
    for(auto a : se) cout << a << "\n";
    return 0;
}