#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int n,w,l; cin >> n >> w >> l;
    queue<int> q; for(int i=0;i<w;i++) q.push(0);
    vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
    
    int total_weight = 0;
    int ans = 0;
    for(int i=0;i<n;ans++){
        total_weight -= q.front();
        q.pop();
        if(total_weight + v[i] > l){
            q.push(0);
        }   
        else{
            total_weight += v[i];
            q.push(v[i]);
            i++;
        }
    }
    cout << ans + w;
}