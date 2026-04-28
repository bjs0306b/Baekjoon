#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin >> n >> m; multiset<int> s; while(n--){int num; cin >> num; s.insert(num);}
    for(auto a : s){
        if(a <= m) m++;
        else break;
    }
    cout << m;
    
    
    return 0;
}