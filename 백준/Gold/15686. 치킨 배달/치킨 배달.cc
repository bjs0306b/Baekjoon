#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> home, chicken;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            int num; cin >> num;
            if(num == 1){
                home.push_back({i,j});
            }
            else if(num == 2){
                chicken.push_back({i,j});
            }
        }
    }
    
    // for(int i=0;i<home.size();i++) cout << home[i].first << " " << home[i].second << "\n";
    // cout << "\n";
    // for(int i=0;i<chicken.size();i++) cout << chicken[i].first << " " << chicken[i].second << "\n";
    // cout << "\n";


    vector<int> v;

    for(int i=0;i<b;i++)  v.push_back(1);
    for(int i=0;i<chicken.size()-b;i++) v.push_back(0);
    sort(v.begin(), v.end());


    int ans = INT32_MAX;
    do{
        int dis_sum = 0;
        for(int i=0;i<home.size();i++){
            int dis_min = INT32_MAX;
            for(int j=0;j<v.size();j++){
                if(v[j]){
                    dis_min = min(dis_min, (abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second)));
                }
            }
            dis_sum += dis_min;
        }

        ans = min(dis_sum , ans);
    }while(next_permutation(v.begin(), v.end()));

    cout << ans;

    
    return 0;
}