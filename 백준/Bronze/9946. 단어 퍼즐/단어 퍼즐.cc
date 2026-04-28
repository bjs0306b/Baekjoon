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
    string a,b; 
    for(int i=1;;i++){
        cin >> a >> b;
        if(a == "END" && b == "END") break;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        if(a==b) cout << "Case " << i << ": same\n";
        else cout << "Case " << i << ": different\n";
    }
    
    
    return 0;
}