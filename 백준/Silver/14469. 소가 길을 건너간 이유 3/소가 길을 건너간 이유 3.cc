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

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v;
    while(n--){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);

    int ans = 0;
    for(auto k : v){
        if(ans <= k.first) ans = k.first + k.second;
        else ans += k.second;
    }
    cout << ans;
    return 0;
}