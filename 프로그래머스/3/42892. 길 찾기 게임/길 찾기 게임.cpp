#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node{
    int idx, x, y;
    
    bool operator<(const node other) const{
        if(y == other.y) return x < other.x;
        return y > other.y;
    }
};

vector<int> v[100002], ans1, ans2;

int dfs(vector<node>& vec){
    if(vec.size() == 1) return vec[0].idx;
    
    sort(vec.begin(), vec.end());
    int par = vec[0].idx;
    vector<node> lv, rv;
    for(auto k : vec){
        if(k.x < vec[0].x) lv.push_back(k);
        if(k.x > vec[0].x) rv.push_back(k);
    }
    if(lv.size()) v[par].push_back(dfs(lv));
    if(rv.size()) v[par].push_back(dfs(rv));

    return par;
}

void pre_order(int cur){
    ans1.push_back(cur);
    for(auto k : v[cur]) pre_order(k);
}

void post_order(int cur){
    for(auto k : v[cur]) post_order(k);
    ans2.push_back(cur);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<node> temp;
    for(int i=0;i<nodeinfo.size();i++){
        temp.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    
    int root = dfs(temp);
    pre_order(root);
    post_order(root);
    
    vector<vector<int>> ans;
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;
}