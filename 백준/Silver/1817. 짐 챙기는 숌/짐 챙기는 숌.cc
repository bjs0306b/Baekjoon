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
    int a,b; cin >> a >> b;
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<a;i++){
        int num; cin >> num;
        if(cnt + num > b){
            ans++;
            cnt = num;
        }
        else cnt += num;  
    }
    if(cnt) ans++; cout << ans;
    
    
    return 0;
}