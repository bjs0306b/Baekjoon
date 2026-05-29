#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int s, e;
    bool operator<(const node other) const{
        if(s == other.s) return e < other.e;
        return s > other.s;
    }
};

int solution(vector<vector<int>> routes) {
    priority_queue<node> pq;
    for(auto k : routes) pq.push({k[0], k[1]});
    int ret = 0;
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int temp = t.e;
        cout << t.s << " " << t.e << "\n";
        ret++;
        for(;;){
            if(pq.empty()) break;
            auto tt = pq.top(); 
            if(temp >= tt.s){
                temp = min(tt.e, temp);
                pq.pop();
            }
            else break;
        }
    }
    
    return ret;
}