#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());

    auto iter = max_element(v.begin(), v.end(), cmp);
    int ans = iter->second;

    auto iter2 = max_element(v.begin(), iter, cmp);
    auto iter3 = iter;
    while(iter2 != v.begin()){
        ans += (iter3->first-iter2->first) * iter2->second;
        iter3 = iter2;
        iter2 = max_element(v.begin(), iter2, cmp);
    }
    ans += (iter3->first-iter2->first) * iter2->second;

    if(iter != --v.end()){
        iter2 = max_element(iter+1, v.end(), cmp);
        iter3 = iter;
        while(iter2 != --v.end()){
            ans += (iter2->first-iter3->first) * iter2->second;
            iter3 = iter2;
            iter2 = max_element(iter2+1, v.end(), cmp);
        }
        ans += (iter2->first-iter3->first) * iter2->second;
        
    }
    cout << ans;
    //cout << iter->second;

    return 0;
}