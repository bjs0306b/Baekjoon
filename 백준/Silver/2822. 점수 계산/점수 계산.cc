#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool bibi(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<pair<int,int>> v;
    set<int> s;
    for(int i=1;i<9;i++){
        int num;cin>>num;
        v.push_back({num,i});
    }
    sort(v.begin(), v.end(), bibi);
    int sum=0;
    for(int i=0;i<5;i++) {sum += v[i].first; s.insert(v[i].second);}
    cout << sum << "\n";
    for(auto a : s) cout << a << " ";

    return 0;
}