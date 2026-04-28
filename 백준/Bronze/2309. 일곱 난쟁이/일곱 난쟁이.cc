#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int sum=0;
    set<int> s;
    for(int i=0;i<9;i++) {
        int num; cin >> num; sum += num;
        s.insert(num);
    }
    int t = sum - 100;
    for(int a : s){
        auto f = find(s.begin(), s.end(), t-a);
        if (f != s.end()){
            s.erase(a);
            s.erase(*f);
            break;
        }
    }
    for(int a:s) cout << a << "\n";
    
    
    return 0;
}