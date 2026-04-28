#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

vector<int> s;
set<int> ans;
void func(int n, int sum){
    if(n == s.size()){
        ans.insert(sum);
        return;
    }
    else{
        func(n+1, sum+s[n]);
        func(n+1, sum);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        if(a == 0) cout << "no" << "\n";
        cout << "yes" << "\n";
    }
    
    return 0;
}