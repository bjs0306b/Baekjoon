#include <string>
#include <vector>
#include <iostream>

using namespace std;
int n;
int cost[300001][2]; // cost[x][y] : y=1 -> 현재 꺼를 쓸 때 , y=0 -> 현재 꺼를 안쓸 때의 서브 트리의 최소값
vector<int> v[300001];
vector<int> node_sale;

void dfs(int cur){
    for(auto k : v[cur]){
        dfs(k);
    }
    
    // 리프노드일 때
    if(v[cur].size() == 0){
        cost[cur][0] = 0;
        cost[cur][1] = node_sale[cur];
        return;
    }
    
    // 현재 꺼 안쓸 때 -> 자식 꺼 1개는 무조건 써야대
    int mn = INT32_MAX;
    for(auto k : v[cur]){ // 얘를 무조건 쓸 때
        int sum = 0;
        for(auto kk : v[cur]){
            if(k == kk) sum += cost[kk][1];
            else sum += min(cost[kk][0], cost[kk][1]);
        }
        mn = min(mn, sum);
    }
    cost[cur][0] = mn;
    
    // 현재 꺼 쓸 때
    int sum = 0;
    for(auto k : v[cur]){
        sum += min(cost[k][1], cost[k][0]);
    }
    cost[cur][1] = node_sale[cur] + sum;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    n = sales.size();
    node_sale.push_back(0);
    for(auto k : sales) node_sale.push_back(k);

    for(int i=1;i<=n;i++) cost[i][0] = cost[i][1] = INT32_MAX;
    for(auto k : links){
        v[k[0]].push_back(k[1]);
    }
    dfs(1);
    
    return min(cost[1][0], cost[1][1]);
}