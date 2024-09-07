#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b; // 건물 수, 길 수
        
        int cnt[a+1]; for(int i=1;i<=a;i++) cnt[i] = 0;
        vector<int> time(a+1); for(int i=1;i<=a;i++) cin >> time[i];
        vector<int> vec[a+1];
        vector<int> total_time(a+1); for(int i=1;i<=a;i++) total_time[i] = 0;
        for(int i=0;i<b;i++){
            int s,e; cin >> s >> e;
            vec[s].push_back(e);
            cnt[e]++;
        }
    
        int arrive; cin >> arrive;

        queue<int> q;
        for(int i=1;i<=a;i++){
            if(!cnt[i]){
                q.push(i);
                total_time[i] = time[i];
            }
        }

        
        while(!q.empty()){

            int node = q.front(); q.pop();

            for(auto k : vec[node]){
                total_time[k] = max(total_time[node] + time[k], total_time[k]);
                if(--cnt[k] == 0) q.push(k);
            }
        }

        cout << total_time[arrive] << "\n";
    }
    
    return 0;
}