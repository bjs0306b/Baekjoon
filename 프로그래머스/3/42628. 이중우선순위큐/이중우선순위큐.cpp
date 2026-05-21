#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int,int> cnt;
priority_queue<int> mx_pq;
priority_queue<int, vector<int>, greater<int>> mn_pq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int i_cnt = 0, d_cnt = 0;
    
    for(auto k : operations){
        char c = k[0];
        int num = stoi(k.substr(2));
        if(c == 'I'){
            i_cnt++;
            mx_pq.push(num);
            mn_pq.push(num);
            cnt[num]++;
        }else{
            if(i_cnt == d_cnt) continue;
            d_cnt++;
            if(num == -1){
                for(;;){
                    int t = mn_pq.top(); mn_pq.pop();
                    if(cnt[t] > 0){
                        cnt[t]--;
                        break;
                    }
                }
            }else{
                for(;;){
                    int t = mx_pq.top(); mx_pq.pop();
                    if(cnt[t] > 0){
                        cnt[t]--;
                        break;
                    }
                }
            }
        }
    }
    if(i_cnt == d_cnt) return {0,0};
    else if(i_cnt == d_cnt + 1){
        for(;;){
            int t = mn_pq.top(); mn_pq.pop();
            if(cnt[t] > 0){
                return {t, t};
            }
        }
    }
    
    for(;;){
        int t = mx_pq.top(); mx_pq.pop();
        if(cnt[t] > 0){
            cnt[t]--;
            answer.push_back(t);
            break;
        }
    }
    
    for(;;){
        int t = mn_pq.top(); mn_pq.pop();
        if(cnt[t] > 0){
            answer.push_back(t);
            cnt[t]--;
            break;
        }
    }
    
    return answer;
}