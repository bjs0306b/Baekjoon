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
    int a,b,c; cin >> a >> b >> c;
    int ans = 0;
    bool visited[a]; memset(visited, false, sizeof(visited));
    vector<int> easy, hard;
    for(int i=0;i<a;i++){
        int m,n; cin >> m >> n;
        easy.push_back(m);
        hard.push_back(n);
    }
    sort(easy.begin(), easy.end(), greater<int>());
    sort(hard.begin(), hard.end(), greater<int>());
    
    for(int i=0;i<a;i++){
        if(!visited[i] && hard[i] <= b){
            visited[i] = true;
            ans += 140;
            c--;
        }   
        if(c == 0) break;
    }
    for(int i=0;i<a;i++){
        if(!visited[i] && easy[i] <= b){
            visited[i] = true;
            ans += 100;
            c--;
        }
        if(c == 0) break;
    }
    cout << ans;
    
    return 0;
}