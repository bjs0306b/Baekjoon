#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    stack<int> s[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num; cin >> num;    
            s[j].push(num);
        }
    }
    int cnt = 0;
    for(;;){
        int mx = INT32_MIN;
        int mx_idx = 0;
        for(int i=0;i<n;i++){
            if(!s[i].empty() && s[i].top() > mx){
                mx = s[i].top();
                mx_idx = i;
            }
        }
        if(++cnt == n){cout << mx; break;}
        s[mx_idx].pop();    
    }
    
    return 0;
}