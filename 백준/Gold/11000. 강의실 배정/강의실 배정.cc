#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    multiset<int> st;
    for(int i=0;i<n;i++){
        if(st.size() == 0) st.insert(v[i].second);
        else{
            auto temp = st.upper_bound(v[i].first);
            if(temp == st.begin()){
                st.insert(v[i].second);
            }
            else{
                st.erase(--temp);
                st.insert(v[i].second);
            }
        }
    }
    cout << st.size();
    
    return 0;
}