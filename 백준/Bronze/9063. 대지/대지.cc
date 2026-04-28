#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int minx=10001,maxx=-10001,miny=10001,maxy=-10001;
    while(n--){
        int a,b; cin >> a>>b;
        if(a>maxx) maxx = a;
        if(a<minx) minx = a;

        if(b>maxy) maxy = b;
        if(b<miny) miny = b;
    }
    long long ans = (maxx-minx)*(maxy-miny);
    cout << ans;
    
    return 0;
}