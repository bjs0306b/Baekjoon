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
    // 두 점이 x 또는 y 좌표가 같을 때.
    else if(a.second != b.second) return a.second < b.second;
    return a.first < b.first; 
}

void input(){
    cin >> n;
    v.resize(n);
    for(long long i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    for(long long i=1;i<n;i++){
        if(v[0].second > v[i].second || (v[0].second == v[i].second && v[0].first > v[i].first)) swap(v[0], v[i]);
    }

    sort(v.begin()+1, v.end(), cmp); // 0번 점을 기준으로 CCW 정렬.
}

void solve(){
    stack<long long> st;
    st.push(0); st.push(1);
    for(long long i=2;i<n;i++){
        while(st.size() >= 2){
            long long temp1 = st.top();
            st.pop();
            long long temp2 = st.top();
            if(ccw(v[temp2], v[temp1], v[i]) > 0){ // CCW
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