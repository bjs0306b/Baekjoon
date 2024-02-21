#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    for(auto a : s){
        if(a != 'C' && a != 'A' && a != 'M' && a != 'B' && a != 'R' && a != 'I' && a != 'D' && a != 'G' && a != 'E')
            cout << a;
    }
    
    
    return 0;
}