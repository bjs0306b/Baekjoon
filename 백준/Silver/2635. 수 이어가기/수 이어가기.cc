#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

vector<int> v;
vector<int> ans;

int func(int a, int b){
    v.push_back(b);
    while(a >= b){
        int temp = a;
        a = b;
        b = temp - a;
        v.push_back(b);
    }
    return v.size();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int mx = 0;
    for(int i=n/2;i<=n;i++){
        int num = func(n,i);
        if(num > mx){
            mx = num;
            ans = v;
        }
        v.clear();
    }
    cout << mx+1 << "\n";
    cout << n << " ";
    for(auto k : ans) cout << k << " "; 
    return 0;
}