#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x1,y1,x2,y2; cin >>x1>>y1>>x2>>y2;
        int num, cnt = 0; cin >> num;
        while(num--){
            int x,y,r; cin >>x>>y>>r;
            float dis1 = sqrt(pow((x-x1),2)+pow((y-y1),2));
            float dis2 = sqrt(pow((x-x2),2)+pow((y-y2),2));

            if(dis1 < r && dis2 > r || dis1 > r && dis2 < r) cnt++;
        }
        cout << cnt << "\n";
    }
    
    return 0;
}