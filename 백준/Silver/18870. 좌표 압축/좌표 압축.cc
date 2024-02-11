#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; set<int> s; map<int,int> m; 
    cin >> n; int arr[n]; for(int i=0;i<n;i++){int num; cin >> num; arr[i] = num; s.insert(num);}
    int cnt = 0; for(auto a : s){m.insert({a, cnt++});}
    for(int i=0;i<n;i++){
        cout << m[arr[i]] << " ";
    }
    
    return 0;
}