#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    queue<pair<int,int>> q; // {location, priority}
    for(int i=0;i<priorities.size();i++) q.push({i, priorities[i]});
    sort(priorities.begin(), priorities.end());
    int answer = 0;
    while(!q.empty()){
        auto f = q.front(); q.pop();
        if(f.second == priorities[priorities.size()-1]){
            answer++;
            priorities.pop_back();
            if(f.first == location) return answer;
        } 
        else q.push(f);
    }
    
    return answer;
}