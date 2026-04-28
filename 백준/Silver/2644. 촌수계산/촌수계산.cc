#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

bool visited[101], arr[101][101];
deque<int> v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int a,b; cin >> a >> b;
    int num; cin >> num;
    while(num--){
        int m,n; cin >> m >> n;
        arr[m][n] = 1;
        arr[n][m] = 1;
    }
    v.push_back(a);
    int cnt =0;
    visited[a] = true;
    while(!v.empty()){
        int size = v.size(); cnt++;
        for(int i=0;i<size;i++){
            int num = v.front();
            v.pop_front();
            for(int i=1;i<=n;i++){
                if(!visited[i] && arr[num][i]){
                    if(i == b){cout << cnt; return 0;}
                    v.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
    cout << -1;
    return 0;
}