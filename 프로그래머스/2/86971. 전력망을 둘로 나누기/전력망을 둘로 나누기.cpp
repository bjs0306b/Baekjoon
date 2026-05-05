#include <string>
#include <vector>

using namespace std;
vector<int> v[101];
int cnt;

void dfs(int cur, int ban, int pre){
    cnt++;
    for(auto k : v[cur]){
        if(k == ban || k == pre) continue;
        dfs(k, ban, cur);
    }
}

int solution(int n, vector<vector<int>> wires) {
    for(auto k : wires){
        v[k[0]].push_back(k[1]);
        v[k[1]].push_back(k[0]);
    }
    
    int cnt1, cnt2, ans = INT32_MAX;
    for(auto k : wires){
        cnt = 0;
        dfs(k[0], k[1], -1);
        cnt1 = cnt;
        cnt = 0;
        dfs(k[1], k[0], -1);
        cnt2 = cnt;
        ans = min(ans, abs(cnt1 - cnt2));
    }
    return ans;
}