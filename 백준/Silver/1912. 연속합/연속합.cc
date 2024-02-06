#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n; cin >> n;
    long long mx = -1001;
    vector<long long> v,v2; for(long long i=0;i<n;i++){long long num; cin >> num; if(mx < num) mx=num; if(num==0) continue; v.push_back(num); }
    
    n = v.size();
    for(long long i=0;i<n;){
        long long temp = i;
        long long sum = 0;
        while(v[temp]*v[i] >= 0) {sum += v[i]; i++; if(i>=n) break;}
        v2.push_back(sum);
    }
    if(v2.size() < 3) {cout << max(mx, *max_element(v2.begin(), v2.end())); return 0;}
    if(v2[0]<0 && v2.size() > 1)  v2.erase(v2.begin()); 
    if(v2[v2.size()-1]<0 && v2.size() > 1) v2.erase(v2.end()-1);
    if(v2.size() > 2){
        for(int i=0;i<v2.size()-2;i+=2){
            if(v2[i]+v2[i+1] > 0) v2[i+2] += v2[i]+v2[i+1];
        }
    }
    mx = max(mx, *max_element(v2.begin(), v2.end()));
    cout << mx;   
    
    return 0;
}