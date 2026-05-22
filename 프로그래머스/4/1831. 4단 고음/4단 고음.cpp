#include <unordered_map>
#include <cmath>
using namespace std;

long long three_pow[30];
int cnt;
void dfs(int star, long long cur){
    // 3 ^ (현재 앞에 있어야 하는 * 수) 보다 작으면 만들 수가 없음.
    if(three_pow[(star+1)/2] > cur) return;
    
    if(cur == 1){
        if(star == 0) cnt++;
        return;
    }

    dfs(star + 1, cur - 1);
    if(star >= 2 && cur % 3 == 0) dfs(star - 2, cur / 3);
}

int solution(int n) {
    cnt = 0;
    long long temp = 1;
    for(int i=0;i<30;i++){
        three_pow[i] = temp;
        temp *= 3;
    }
    dfs(0, n);
    return cnt;
}