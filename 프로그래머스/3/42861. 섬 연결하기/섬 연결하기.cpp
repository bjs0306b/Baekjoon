#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int a, b, dis;
    bool operator<(const node other) const{
        if(dis == other.dis) return a < other.a;
        return dis > other.dis;
    }
};

priority_queue<node> pq;

vector<int> parent;

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

int solution(int n, vector<vector<int>> costs) {
    for(auto k : costs){
        pq.push({k[0], k[1], k[2]});
    }
    parent.resize(n); for(int i=0;i<n;i++) parent[i] = i;
    
    int cnt = n-1;
    int answer = 0;
    while(cnt){
        auto t = pq.top(); pq.pop();
        int aa = find(t.a), bb = find(t.b);
        if(aa == bb) continue;
        
        if(aa < bb) swap(aa, bb);
        parent[aa] = bb;
        answer += t.dis;
        cnt--;
    }
    
    return answer;
}