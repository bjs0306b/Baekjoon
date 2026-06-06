#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> a) {
    unordered_map<int, vector<int>> um;
    for(int i=0;i<a.size();i++){
        um[a[i]].push_back(i);
    }
    vector<bool> visited;
    int ans = 0;
    for(auto k : um){
        if (k.second.size() * 2 <= ans) continue;
        visited.assign(a.size(), false);

        vector<int> idx = k.second;
        int cnt = 0;
        for(auto kk : idx){

            // 왼쪽꺼
            if(kk != 0 && a[kk-1] != k.first && !visited[kk-1]){
                visited[kk-1] = true;
                cnt += 2;
            }
            // 오른쪽꺼
            else if(kk != a.size()-1 && a[kk+1] != k.first && !visited[kk+1]){
                visited[kk+1] = true;
                cnt += 2;
            }
        }
        
        ans = max(ans, cnt);
    }
    
   return ans;
}
