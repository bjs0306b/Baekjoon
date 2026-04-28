#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    set<string> se;
    for(int i=0;i<s.size();i++){
        for(int j=1;j<=s.size()-i;j++){
            se.insert(s.substr(i,j));
        }
    }
    cout << se.size();
    
    return 0;
}