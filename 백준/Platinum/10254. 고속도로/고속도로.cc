#include <bits/stdc++.h>
using namespace std;

long long n;
vector<pair<long long,long long>> v;

long long ccw(pair<long long,long long> a, pair<long long,long long> b, pair<long long,long long> c){
    return a.first * b.second + b.first * c.second + c.first * a.second - b.first * a.second - c.first * b.second - a.first * c.second;
}

bool cmp(pair<long long,long long> a, pair<long long,long long> b){
    long long ccw_value = ccw(v[0], a, b);
    if(ccw_value != 0) return ccw_value > 0;
    else if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

void input(){
    cin >> n;
    v.resize(n);
    for(long long i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    for(long long i=1;i<n;i++) if(v[i].second < v[0].second || (v[i].second == v[0].second && v[i].first < v[0].first)) swap(v[0], v[i]);
    sort(v.begin()+1, v.end(), cmp);
}

long long ret_dis(pair<long long,long long> a, pair<long long,long long> b){
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

void solve(){
    // convex hull (CCW로 정렬됨.)
    stack<long long> st;
    st.push(0); st.push(1);
    for(long long i=2;i<n;i++){
        while(st.size() >= 2){
            long long temp1 = st.top();
            st.pop();
            long long temp2 = st.top();
            if(ccw(v[temp2], v[temp1], v[i]) > 0){
                st.push(temp1);
                break;
            }
        }
        st.push(i);
    }

    vector<long long> convex_hull; 
    // LIFO 이므로 CCW -> CW로 변환. 따라서 CW로 돌면서 캘리퍼스 알고리즘을 행하는데 두 선분의 CCW(외적이 양수)가 되면 멈추고 최댓값 갱신
    while(!st.empty()){
        convex_hull.push_back(st.top());
        st.pop();
    }
    
    pair<long long,long long> ans;
    long long max_dis = 0;
    long long size = convex_hull.size();
    long long j = 1;
    for(long long i=0;i<size;i++){
        pair<long long,long long> i_edge = {v[convex_hull[i]].first - v[convex_hull[(i+1)%size]].first, v[convex_hull[i]].second - v[convex_hull[(i+1)%size]].second};
        pair<long long,long long> j_edge;
        for(;;j++){  
            if(j >= size) j %= size;
            j_edge = {v[convex_hull[j]].first - v[convex_hull[(j+1)%size]].first, v[convex_hull[j]].second - v[convex_hull[(j+1)%size]].second};
            if(ccw({0,0}, i_edge, j_edge) >= 0) break;
        }
        
        long long dis = ret_dis(v[convex_hull[i]], v[convex_hull[j]]);
        if(max_dis < dis){
            max_dis = dis;
            ans = {convex_hull[i], convex_hull[j]};
        }
    }
    cout << v[ans.first].first << " " << v[ans.first].second << " " << v[ans.second].first << " " << v[ans.second].second << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long t; cin >> t;
    while(t--){
        input();
        solve();
    }
    return 0;
}