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
    int a,b,c,m;
    cin >> a >> b >> c >> m;
    int t = 0;
    int w = 0; // 일의 양
    int x = 0; // 피로도
    if(a>m){cout << "0"; return 0;}
    for(;t<24;t++){
        if(x+a<=m){
            x += a;
            w += b;
        }
        else{
            x -= c;
            if(x<0) x = 0;
        }
    }
    cout << w;
    return 0;
}