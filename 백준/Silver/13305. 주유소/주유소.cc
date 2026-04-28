#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
long long n, dis[100001],sum=0;
vector<pair<int,int>> cost;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    dis[0] = 0;
    for(int i=1;i<n;i++) {int num; cin >> num; dis[i] = dis[i-1]+num;}
    long long dissum = dis[n-1];
    for(int i=1;i<=n;i++) {int num; cin >> num; cost.push_back({num,i});}
    sort(cost.begin(), cost.end(), cmp);
    for(pair<int,int> a : cost){
        if(dissum  > dis[a.second-1]){
            sum += a.first * (dissum-dis[a.second-1]);
            dissum  = dis[a.second-1];
        }
        if(dissum == 0) break;
    }
    cout << sum;
    
    return 0;
}