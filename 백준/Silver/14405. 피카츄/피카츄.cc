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
    bool check = true;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'p'){
            if(s[++i] != 'i'){check = false; break;}
        }
        else if(s[i] == 'k'){
            if(s[++i] != 'a'){check = false; break;}
        }
        else if(s[i] == 'c'){
            if(s[++i] != 'h' || s[++i] != 'u'){check = false; break;}
        }
        else{
            check = false; break;
        }
    }
    if(check) cout << "YES";
    else cout << "NO";
    
    
    return 0;
} 