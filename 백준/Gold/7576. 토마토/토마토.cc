#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <deque>
using namespace std;

int arr[1005][1005];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(arr, -1, sizeof(int)*1005*1005);
    int a,b,days=0; cin >> a>>b;deque<pair<int,int>> deq,deq2;
    for(int i=1;i<b+1;i++) for(int j=1;j<a+1;j++) {cin >> arr[i][j]; if(arr[i][j] == 1) deq.push_back({i,j});}
    
    while(!deq.empty()){
        deq2 = deq;
        while(!deq2.empty()){
            int a = deq2.front().first, b = deq2.front().second;
            deq2.pop_front();
            deq.pop_front();
            if(arr[a+1][b] == 0) {arr[a+1][b]=1; deq.push_back({a+1,b});}
            if(arr[a-1][b] == 0) {arr[a-1][b]=1; deq.push_back({a-1,b});}
            if(arr[a][b+1] == 0) {arr[a][b+1]=1; deq.push_back({a,b+1});}
            if(arr[a][b-1] == 0) {arr[a][b-1]=1; deq.push_back({a,b-1});}
        }
        days++;
    }
    bool check =true;
    for(int i=1;i<b+1;i++) for(int j=1;j<a+1;j++) if(arr[i][j] == 0) check = 0;
    if(check) cout << days-1;
    else cout << -1;
    
    return 0;
}