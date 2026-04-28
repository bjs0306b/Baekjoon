#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,cnt=0; cin >>a>>b; set<int> s; for(int i=0;i<a;i++){int num; cin >> num; s.insert(num);}
    for(auto a : s){
        if(s.find(b-a) != s.end()) cnt++;
    }
    cout << cnt/2;
    return 0;
}