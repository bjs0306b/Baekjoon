#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<pair<string,int>> st;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        st.insert({s, i});
    }
    vector<pair<string,int>> v; for(auto k : st) v.push_back(k);
    int mx = 0;
    pair<pair<string,int>, pair<string,int>> ans = {{"", INT32_MAX},{"", INT32_MAX} };   
    for(int i=0;i<v.size()-1;i++){
        int k_max = -1;
        for(int k=i+1;k<v.size();k++){
            int size = min(v[i].first.size(), v[k].first.size());
            int j;

            bool flag = false;
            for(j=0;j<size;j++){
                if(v[i].first[j] != v[k].first[j]){
                    if(k_max > j){
                        flag = true;
                        break;
                    }
                    if(mx == j){
                        int ans_min = min(ans.first.second, ans.second.second), ans_max = max(ans.first.second, ans.second.second);
                        int v_min = min(v[i].second, v[k].second), v_max = max(v[i].second, v[k].second);
                        if(v_min < ans_min || (v_min == ans_min && v_max < ans_max)){
                            if(v[i].second < v[k].second){
                                ans = {v[i], v[k]};
                            }
                            else{
                                ans = {v[k], v[i]};
                            }
                        }
                    }
                    else if(mx < j){
                        mx = j;
                        if(v[i].second < v[k].second){
                            ans = {v[i], v[k]};
                        }
                        else{
                            ans = {v[k], v[i]};
                        }
                    }
                    break;
                }
            }
            if(flag) break;
            if(j == size){
                if(mx == j){
                    int ans_min = min(ans.first.second, ans.second.second), ans_max = max(ans.first.second, ans.second.second);
                    int v_min = min(v[i].second, v[k].second), v_max = max(v[i].second, v[k].second);
                    if(v_min < ans_min || (v_min == ans_min && v_max < ans_max)){
                        if(v[i].second < v[k].second){
                            ans = {v[i], v[k]};
                        }
                        else{
                            ans = {v[k], v[i]};
                        }
                    }
                }
                else if(mx < j){
                    mx = j;
                    if(v[i].second < v[k].second){
                        ans = {v[i], v[k]};
                    }
                    else{
                        ans = {v[k], v[i]};
                    }
                }
            }
        }
    }
    cout << ans.first.first << "\n" << ans.second.first; 

    return 0;
}