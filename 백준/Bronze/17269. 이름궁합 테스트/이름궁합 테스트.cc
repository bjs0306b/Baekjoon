#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    int arr[26] = {3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1};
    deque<int> dq;
    string a,b; cin >> a >> b;
    bool check = false;
    if(n > m) check = true;
    if(check) swap(n,m);
    for(int i=0;i<n;i++){
        dq.push_back(arr[a[i]-'A']);
        dq.push_back(arr[b[i]-'A']);
    }
    for(int i = n; i < m; i++){
        if(check) dq.push_back(arr[a[i]-'A']);
        else dq.push_back(arr[b[i]-'A']);
    }
    
    while(dq.size() > 2){
        int size = dq.size();
        for(int i=0;i<size-1;i++){
            dq.push_back((dq[i]+dq[i+1])%10);
        }
        for(int i=0;i<size;i++)dq.pop_front(); 
    }
    if(dq.front() != 0) cout << dq.front();
    cout << dq.back() << "%";
    return 0;
}