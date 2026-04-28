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
    for(long long i=0;i<n;i++) cin >> v[i].first >> v[i].second; // 입력
    for(long long i=1;i<n;i++){ // 0번 점 정하기
        if(v[i].second < v[0].second || (v[i].second == v[0].second && v[i].first < v[0].first)) swap(v[0], v[i]);
    }
    sort(v.begin()+1, v.end(), cmp);
}

void solve(){
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
    cout << st.size();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}