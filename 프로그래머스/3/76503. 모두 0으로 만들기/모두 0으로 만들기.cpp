#include <string>
#include <vector>

using namespace std;

vector<long long> v[300000];
vector<long long> value;

long long ans;
void dfs(int cur, int pre){
    for(auto k : v[cur]){
        if(k == pre) continue;
        dfs(k, cur);
        value[cur] += value[k];
        ans += abs(value[k]);
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long sum = 0;
    for(auto k : a) sum += k;
    if(sum != 0) return -1;
    int n = a.size();
    
    for(auto k : a) value.push_back((long long)k);
    
    for(int i=0;i<n;i++) v[i].clear();
    
    ans = 0;
    for(auto& k : edges){
        v[k[0]].push_back(k[1]);
        v[k[1]].push_back(k[0]);
    }
    
    dfs(0, -1);
    return ans;
}