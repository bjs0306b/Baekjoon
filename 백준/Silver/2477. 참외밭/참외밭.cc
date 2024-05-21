#include<bits/stdc++.h>
using namespace std;
int arr[5];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v;
    vector<int> big;
    for(int i=0;i<6;i++){
        int a,b; cin >> a >> b; 
        arr[a]++; 
        v.push_back({a,b});
    }   
    for(int i=1;i<=4;i++){
        if(arr[i] == 1) big.push_back(i);
    }
    
    vector<pair<int,int>> v2;
    for(int i=0;i<2;i++){
        for(int j=0;j<6;j++){
            v2.push_back({v[j].first, v[j].second});
        }
    }

    for(int i=0;i<11;i++){
        if(v2[i].first == big[0] && v2[i+1].first == big[1] || v2[i].first == big[1] && v2[i+1].first == big[0]){
            cout << n*(v2[i].second*v2[i+1].second - v2[i+3].second*v2[i+4].second);
            return 0;
        }
    }
    return 0;
}