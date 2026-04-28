#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int ans1 = 0;
    vector<int> v;
    
    for(int i=0;i<6;i++){
        int num; cin >> num;
        v.push_back(num);
    }

    int a,b; cin >> a >> b;

    for(int i=0;i<v.size();i++){
        ans1 += (v[i]+a-1)/a;
    }
    
    int ans2 = n/b, ans3 = n%b;
    cout << ans1 << "\n" << ans2 << " " << ans3;
    
    return 0;
}