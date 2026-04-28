#include <bits/stdc++.h>
using namespace std;

bool solve(){
    long long n; cin >> n;
    if(n == 0) return false;
    vector<long long> v(n); for(long long i=0;i<n;i++) cin >> v[i];
    v.push_back(0);

    long long ans = 0;
    stack<long long> st;
    for(long long i=0;i<n+1;i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            long long t = st.top();
            st.pop();

            long long a; // 가로
            if(st.empty()) a = i;
            else a = i - st.top() - 1; 
            long long b = v[t]; // 세로 
            ans = max(ans, a*b);
        }
        st.push(i);
    }
    cout << ans << "\n";

    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    for(;;){
        if(!solve()) break;
    }

    return 0;
}