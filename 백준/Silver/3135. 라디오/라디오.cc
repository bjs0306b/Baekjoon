#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    int n; cin >> n; vector<int> v; v.push_back(abs(a-b));
    for(int i=0;i<n;i++){
        int num; cin >> num;
        v.push_back(abs(num-b)+1);
    }
    sort(v.begin(), v.end());
    cout << v[0];
    
    
    return 0;
}