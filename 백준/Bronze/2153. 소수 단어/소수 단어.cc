#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int sum = 0;
    for(auto k : s){
        if(k >= 'a' && k <= 'z') sum += k - 'a' + 1;
        else sum += k - 'A' + 27;
    }
    bool ans = true;
    for(int i=2;i<=sqrt(sum);i++){
        if(sum%i==0){ans = false; break;}   
    }
    if(ans) cout << "It is a prime word.";
    else cout << "It is not a prime word.";
    
    return 0;
}