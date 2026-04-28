#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    map<double,double> s;
    for(int i=0;i<n;i++){
        double x,y; cin >> x >> y;
        s.insert({x,y});
    }

    auto iter = s.begin();
    for(;iter!=--s.end();iter++){
        auto temp = iter;
        temp++;
        if(iter->second == temp->second)iter->second = 0; 
        else if(iter->second < temp->second)iter->second = 1; 
        else iter->second = -1;
    }
    iter->second = 0;

    int m; cin >> m;
    for(int i=0;i<m;i++){
        double f; cin >> f;
        auto iter2 = s.upper_bound(f);
        cout << (--iter2)->second << "\n";
    }
    return 0;
}