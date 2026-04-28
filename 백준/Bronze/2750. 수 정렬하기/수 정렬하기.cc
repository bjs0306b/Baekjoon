#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        s.insert(num);
    }
    for(int a : s){
        cout << a << "\n";
    }
    
    return 0;
}