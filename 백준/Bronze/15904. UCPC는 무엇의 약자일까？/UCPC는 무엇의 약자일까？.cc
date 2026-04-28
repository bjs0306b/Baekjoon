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
    string s; getline(cin, s);
    int cnt = 0;
    for(auto k : s){
        if(cnt == 0 && k == 'U') cnt++;
        else if(cnt == 1 && k == 'C') cnt++;
        else if(cnt == 2 && k == 'P') cnt++;
        else if(cnt == 3 && k == 'C') cnt++;
    }
    if(cnt == 4) cout << "I love UCPC";
    else cout << "I hate UCPC";
    
    return 0;
}