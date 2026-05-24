#include <string>
#include <vector>

using namespace std;

int m;
int ans;
void dfs(int left_cnt, int total_cnt){
    if(total_cnt == m){
        ans++;
        return;
    }
    
    if(left_cnt > 0) dfs(left_cnt-1, total_cnt); // )
    if(left_cnt < m) dfs(left_cnt+1, total_cnt+1); // (
}

int solution(int n) {
    m = n;
    ans = 0;
    
    dfs(1, 1); // 처음은 무조건 ( 이니깐
    
    return ans;
}