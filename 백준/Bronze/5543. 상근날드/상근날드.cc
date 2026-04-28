#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<int> s1,s2;
    for(int i=0;i<3;i++){
        int num; cin >> num; s1.insert(num);
    }
    for(int i=0;i<2;i++){
        int num; cin >> num; s2.insert(num);
    }
    int n1=*s1.begin(); int n2 = *s2.begin();
    cout << n1+n2-50;
    
    
    return 0;
}