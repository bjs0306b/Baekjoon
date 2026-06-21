#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int running_time, arrive_time, idx;
    
    bool operator<(const node other) const{
        if(running_time == other.running_time){
            if(arrive_time == other.arrive_time){
                return idx > other.idx;
            }
            return arrive_time > other.arrive_time;
        }
        return running_time > other.running_time;
    }
};

int solution(vector<vector<int>> jobs) {
    vector<pair<int,int>> job;
    for(auto& k : jobs) job.push_back({k[0], k[1]});
    sort(job.begin(), job.end());
    
    int n = jobs.size();
    int cur_time = 0, cur_idx = 0;
    priority_queue<node> pq;
    int turnaround_time = 0;
    
    for(;;){
        if(pq.empty() && cur_idx != n && job[cur_idx].first > cur_time) cur_time = job[cur_idx].first;
        for(;;){
            if(cur_idx == n || job[cur_idx].first > cur_time) break;
            pq.push({job[cur_idx].second, job[cur_idx].first, cur_idx});
            cur_idx++;
        }
        
        if(pq.empty()) break;
        auto t = pq.top(); pq.pop();
        
        cur_time += t.running_time;
        turnaround_time += (cur_time - t.arrive_time);
        
    }
    
    return turnaround_time / n;
}