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

struct cmp{
    bool operator()(pair<string, int> a, pair<string, int> b){
        if(a.second == b.second){
            if(a.first.size() == b.first.size()) return a.first > b.first;
            return a.first.size() < b.first.size();
        }
        return a.second < b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    map<string, int> mp;
    for(int i=0;i<a;i++){
        string s; cin >> s;
        if(s.size() >= b) mp[s]++;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp > pq;
    for(auto k : mp){
        pq.push({k.first, k.second});
    }
    while(!pq.empty()){
        cout << pq.top().first << '\n';
        pq.pop();
    }
    return 0;
}