#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a>> b; multiset<int> s;
    for(int i=0;i<a;i++){int num; cin >> num; s.insert(num);}
    for(int i=0;i<b;i++){int num; cin >> num; s.insert(num);}
    for(auto a : s) cout << a << " ";
    
    
    return 0;
}