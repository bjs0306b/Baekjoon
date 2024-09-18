#include<bits/stdc++.h>
using namespace std;

int arr[30001];
int visited[30001];
vector<int> vec[30001];
int dp[30001];
int cnt;
int dfs(int n){
    int temp = arr[n];
    for(auto k : vec[n]){
        if(!visited[k]){
            visited[k] = true;
            cnt++;
            temp += dfs(k);
        }
    }
    return temp;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=0;i<m;i++){
        int s,e; cin >> s >> e;
        vec[s].push_back(e);
        vec[e].push_back(s);
    }


    vector<pair<int,int>> bag; // 사람 수 , 사탕
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            int num = dfs(i);
            int people = cnt+1;
            cnt=0;

            bag.push_back({people, num});
        }
    }

    // for(auto k : bag){
    //     cout << k.first << " " << k.second << "\n";
    // }

    for(int i=0;i<bag.size();i++){
        int people = bag[i].first;
        int candy = bag[i].second;

        for(int j=30000 - people; j>=0; j--){
            dp[j + people] = max(dp[j+people], dp[j] + candy); 
        }
    }

    // for(int i=0;i<=n;i++){
    //     cout << dp[i] << " ";
    // }

    cout << dp[k-1];
    
    return 0;
}