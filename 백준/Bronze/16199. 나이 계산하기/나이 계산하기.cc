#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int y1,y2,m1,m2,d1,d2; cin >> y1>>m1>>d1>>y2>>m2>>d2;
    int ans1,ans2,ans3; ans2 = 1 + y2-y1; ans3 = ans2-1;
    
    if(m2-m1 < 0){
        ans1 = ans3-1;
    }
    else if(m2 == m1){
        if(d2 < d1) ans1 = ans3-1;
        else ans1 = ans3;
    }
    else{
        ans1 = ans3;
    }
    cout << ans1 << "\n" << ans2 << "\n" << ans3;
    
    return 0;
}