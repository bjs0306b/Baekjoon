#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    deque<int> d;  d.push_back(1);
    int visit[n+1]; for(int i=1;i<n+1;i++) visit[i]=0; 
    int arr[n+1][n+1]; for(int i=1;i<n+1;i++)for(int j=1;j<n+1;j++) arr[i][j]=0;
    int m; cin >>m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    while(!d.empty()){
        int temp = d.front();
        d.pop_front();
        visit[temp] = 1;
        for(int i=1;i<n+1;i++){
            if(arr[temp][i] == 1 && !visit[i]) d.push_back(i);
        }
    }
    int cnt=0;
    for(int i=1;i<n+1;i++) if(visit[i]) cnt++;
    cout << cnt-1;
    return 0;
}