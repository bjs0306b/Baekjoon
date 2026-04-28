#include<bits/stdc++.h>
using namespace std;


bool sosu(int n){
    int temp = sqrt(n);
    for(int i=2;i<=temp;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for(int i=2;i<=200;i++){
        if(sosu(i)) v.push_back(i);
    }
    vector<int> v2;
    for(int i=0;i<v.size()-1;i++){
        v2.push_back(v[i]*v[i+1]);
    }

    int ans = *upper_bound(v2.begin(), v2.end(), n);
    cout << ans;
    
    return 0;
}