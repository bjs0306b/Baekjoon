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
    while(n--){
        string s; cin >> s;
        if(s.size() > 5 && s.size() < 10) cout << "yes\n";
        else cout << "no\n";
    }
    
    return 0;
}