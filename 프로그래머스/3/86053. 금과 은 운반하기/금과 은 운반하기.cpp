#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 이진 탐색? + paremetric search

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long n = g.size();
    // 최악의 경우 10억 * 2 - 1번을 옮겨야 되는데 1번에 10만의 시간이 들 수 있을듯
    long long st = 1, ed = 4e14;
    long long ans;
    while(st <= ed){
        long long m = (st+ed)/2;
        
        long long g_sum = 0, s_sum = 0, total_sum = 0;
        // g_sum은 g만 몰빵 했을 때 얻을 수 있는 최대, s는 s만 몰빵, total_sum은 그냥 구별 안하고 총 무게
        for(int i=0;i<n;i++){
            long long temp_w = w[i], temp_g = g[i], temp_s = s[i];
            long long move_cnt = m / t[i];
            move_cnt = (move_cnt + 1) / 2;
            long long mx_sum = move_cnt * temp_w;
            total_sum += min(temp_g + temp_s, mx_sum); // 기존의 가진 것 넘어서까지는 얻을 수 없음.
            g_sum += min(temp_g, mx_sum);
            s_sum += min(temp_s, mx_sum);
        }
        
        if(g_sum >= a && s_sum >= b && a + b <= total_sum){ 
            // 충분함 -> 조건을 만족하지만 좀 더 줄여봐도될 거 같다. 
            ans = m;
            ed = m-1;
        }
        else{
            st = m+1;
        }
    }
    return ans;
}