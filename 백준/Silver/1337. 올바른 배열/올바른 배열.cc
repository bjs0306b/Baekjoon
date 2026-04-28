#include<bits/stdc++.h>
using namespace std;

map<long long, bool> arr;
set<long long> s; 
int n; 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;   
    for(int i=0;i<n;i++){long long num; cin >> num; s.insert(num); arr[num] = 1; } 
    int ans = 5;
    for(auto k : s){
        int temp = 0;
        for(int i=k;i<k+5;i++) if(arr[i]) temp++;

        ans = min(ans, 5-temp);
    }

    cout << ans;


    return 0;
}