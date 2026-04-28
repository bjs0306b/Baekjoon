#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >>s;
    for(auto a : s){
        char c = a-3;
        if(c < 'A') c+=26;
        cout << c;
    }
    
    
    return 0;
}