#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


long long solution(int n, vector<int> works) {
    priority_queue<int> pq; for(auto k : works) pq.push(k);
    
    while(n-- && !pq.empty()){
        int t = pq.top(); pq.pop();
        if(t == 0) continue;
        pq.push(--t);
    }
    
    long long ret = 0;
    while(!pq.empty()){
        int t = pq.top(); pq.pop();
        ret += t*t;
    }
    return ret;
}