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

struct cmp{
    bool operator()(pair<string,int> a, pair<string,int> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,n; cin >> m >> n;
    priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> mp;
    for(int i=m;i<=n;i++){
        string temp = to_string(i);
        for(int i=0;i<temp.size();i++){
            char c = temp[i];

            switch(c){
                case '0': temp[i] = '9'; break;
                case '1': temp[i] = '4'; break;
                case '2': temp[i] = '8'; break;
                case '3': temp[i] = '7'; break;
                case '4': temp[i] = '2'; break;
                case '5': temp[i] = '1'; break;
                case '6': temp[i] = '6'; break;
                case '7': temp[i] = '5'; break;
                case '8': temp[i] = '0'; break;
                case '9': temp[i] = '3'; break;
            } 
        }
        mp.push({temp,i});
    }
    int cnt = 0;
    while(!mp.empty()){
        cout << mp.top().second << " ";
        cnt++;
        if(cnt == 10){cout << "\n"; cnt = 0;}
        mp.pop();
    }
    
    return 0;
}