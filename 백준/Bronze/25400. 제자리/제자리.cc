#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    int temp = 1, cnt=0;

    for(auto iter = v.begin(); iter != v.end(); iter++){
        if(*iter == temp){
            temp++;
        }
        else{
            cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}