#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int cnt = 0;
    for(auto iter = s.begin(); iter != s.end(); iter++){
        char c = *iter;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
    }
    cout << cnt;
    
    return 0;
}