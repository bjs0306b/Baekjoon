#include <bits/stdc++.h>
using namespace std;

struct frame{
    int enter_time, num, cnt;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m; cin >> n >> m;
    vector<frame> v;

    for(int t=0;t<m;t++){
        int num; cin >> num;

        bool flag = true;
        for(int i=0;i<v.size();i++){
            if(v[i].num == num){
                flag = false;
                v[i].cnt++;
            }
        }
        if(flag){ // 현재 번호의 사진이 걸려있지 않음.
            if(v.size() < n){ // 사진 틀의 자리가 비어 있음.
                v.push_back({t, num, 1});
            }
            else{ // 사진 틀이 꽉 차있음 -> 추천 받은 횟수가 가장 적은 학생의 사진을 삭제
                int mn_cnt = INT32_MAX, mn_enter_time = -1, mn_idx = -1;
                for(int i=0;i<v.size();i++){
                    if(v[i].cnt < mn_cnt){
                        mn_idx = i;
                        mn_cnt = v[i].cnt;
                        mn_enter_time = v[i].enter_time;
                    }
                    else if(v[i].cnt == mn_cnt){
                        if(mn_enter_time > v[i].enter_time){
                            mn_idx = i;
                            mn_enter_time = v[i].enter_time;
                        }
                    }
                }

                v.erase(v.begin() + mn_idx);
                v.push_back({t, num, 1});
            }
        }
    }

    set<int> ans;
    for(int i=0;i<v.size();i++){
        ans.insert(v[i].num );
    }

    for(auto k : ans) cout << k << " ";

    return 0;
}