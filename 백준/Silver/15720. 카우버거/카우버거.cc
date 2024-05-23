#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    vector<int> v1,v2,v3;
    int ord_sum = 0;
    for(int i=0;i<a;i++){
        int x; cin >> x;
        ord_sum += x;
        v1.push_back(x);
    }
    for(int i=0;i<b;i++){
        int x; cin >> x;
        ord_sum += x;
        v2.push_back(x);
    }
    for(int i=0;i<c;i++){
        int x; cin >> x;
        ord_sum += x;
        v3.push_back(x);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end(), greater<int>());
    sort(v3.begin(), v3.end(), greater<int>());

    int mn = min(a, min(b,c));
    
    int sale = 0;
    for(int i=0;i<mn;i++){
        sale += v1[i];
        sale += v2[i];
        sale += v3[i];
    }
    sale /= 10;

    cout << ord_sum << "\n" << ord_sum - sale;
    return 0;
}