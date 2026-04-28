#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n; vector<pair<int,int>> v;
    while(n--){
        int a,b; cin >>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);
    
    int f,l; f = v[0].first, l = v[0].second;
    int cnt = 1;
    for(int i=1;i<v.size();i++){    
        if(v[i].first >= l){ f = v[i].first, l = v[i].second, cnt++;}
    }
    cout << cnt;
    
    return 0;
}