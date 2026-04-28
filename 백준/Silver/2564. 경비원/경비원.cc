#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m; cin >> n >> m;
    int s; cin >> s;
    vector<pair<int,int>> v(s);
    for(int i=0;i<s;i++){
        cin >> v[i].first >> v[i].second;
    }
    int a,b; cin >> a >> b;

    int ans = 0;
    if(a == 1){
        for(int i=0;i<s;i++){
            switch(v[i].first){
                case 1:{
                    ans += abs(v[i].second - b);
                    break;
                }
                case 2:{
                    ans += m + min(b + v[i].second, n - b + n - v[i].second);
                    break;
                }
                case 3:{
                    ans += b + v[i].second;
                    break;
                }
                case 4:{
                    ans += n - b + v[i].second;
                    break;
                }
            }
        }
    }
    else if(a == 2){
        for(int i=0;i<s;i++){
            switch(v[i].first){
                case 1:{
                    ans += m + min(b + v[i].second, n - b + n - v[i].second);
                    break;
                }
                case 2:{
                    ans += abs(v[i].second - b);
                    break;
                }
                case 3:{
                    ans += b + m - v[i].second;
                    break;
                }
                case 4:{
                    ans += n - b + m - v[i].second;
                    break;
                }
            }
        }
    }
    else if(a == 3){
        for(int i=0;i<s;i++){
            switch(v[i].first){
                case 1:{
                    ans += b + v[i].second;
                    break;      
                }
                case 2:{
                    ans += n - b + v[i].second;
                    break;
                }
                case 3:{
                    ans += abs(v[i].second - b);
                    break;
                }
                case 4:{
                    ans += n + min(b + v[i].second, m - b + m - v[i].second);
                    break;
                }   
            }
        }
    }
    // a == 4
    else{
        for(int i=0;i<s;i++){
            switch(v[i].first){
                case 1:{
                    ans += b + n - v[i].second;
                    break;
                }
                case 2:{
                    ans += m - b + n - v[i].second;
                    break;
                }
                case 3:{
                    ans += n + min(b + v[i].second, m - b + m - v[i].second);
                    break;
                }
                case 4:{
                    ans += abs(v[i].second - b);
                    break;
                }
            }
        }
    }
    cout << ans;

    return 0;
}