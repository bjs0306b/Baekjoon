#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

string s;

bool mo(char c){
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(;;){
        cin >> s;
        if(s == "end") break;

        bool check = false;
        
        for(auto k : s){
            if(mo(k)) check = true;
        }
        if(s.size() > 2){
            for(int i=2;i<s.size();i++){
                if(mo(s[i]) && mo(s[i-1]) && mo(s[i-2])) check = false;
                if(!mo(s[i]) && !mo(s[i-1]) && !mo(s[i-2])) check = false;
            }
        }
        if(s.size() > 1){
            for(int i=1;i<s.size();i++){
                if(s[i] == s[i-1] && s[i] != 'e' && s[i] != 'o'){
                    check = false;
                }
            }
        }
        cout << "<" << s << "> is ";
        if(check) cout << "acceptable.\n";
        else cout << "not acceptable.\n";
    }
    
    
    return 0;
}