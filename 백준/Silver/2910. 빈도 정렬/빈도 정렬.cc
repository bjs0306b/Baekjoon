#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    vector<pair<int,int>> v;
    for(int i=0;i<a;i++){
        int num; cin >> num;
        for(int i=0;i<v.size();i++){
            if(v[i].first == num){
                v[i].second++;
                num = -1;
                break;
            }
        }
        if(num != -1) v.push_back({num,1});
    }
  
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size()-1;j++){
            if(v[j].second < v[j+1].second) swap(v[j],v[j+1]);
        }
    }

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].second;j++){
            cout << v[i].first << " ";
        }
    }
    
    
    return 0;
}