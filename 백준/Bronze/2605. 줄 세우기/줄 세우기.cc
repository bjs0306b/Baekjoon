#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for(int i=1;i<n+1;i++){
        int num; cin>>num;
        v.insert(v.begin()+num, i);
    }
    for(auto iter = v.rbegin(); iter != v.rend(); iter++) cout << *iter << " ";
    
    return 0;
}