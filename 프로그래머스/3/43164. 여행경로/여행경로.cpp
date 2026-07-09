#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<string, int> indexing;
unordered_map<int, string> unindexing;
set<pair<int,int>> v[10000];
vector<bool> visited;
vector<int> ans_his;
int n, idx;
bool flag;

void dfs(int cur, int dep, vector<int> his){
    if(flag) return;
    if(dep == n){
        ans_his = his;
        flag = true;
        return;
    }

    for(auto k : v[cur]){
        if(flag) break;
        
        if(visited[k.second]) continue;
        vector<int> temp = his; temp.push_back(k.first);
        
        visited[k.second] = true;
        dfs(k.first, dep+1, temp);
        visited[k.second] = false;
    }

}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = tickets.size();
    visited.resize(n, false);
    flag = false;
    set<string> st;
    for(auto k : tickets){
        st.insert(k[0]); st.insert(k[1]);
    }
    
    idx = 0;
    for(auto k : st){
        indexing[k] = idx;
        unindexing[idx++] = k;
    }
    
    int num = 0;
    for(auto k : tickets){
        int a = indexing[k[0]], b = indexing[k[1]];
        v[a].insert({b, num++});
    }
    vector<int> temp; temp.push_back(indexing["ICN"]);
    dfs(indexing["ICN"], 0, temp);
    
    vector<string> ret;
    for(auto k : ans_his){
        ret.push_back(unindexing[k]);
    }
    return ret;
}