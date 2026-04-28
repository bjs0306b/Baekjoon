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
    int n; cin >> n;
    while(n--){
        int a,b,sum=0; cin >> a >> b;
        if(a==0) sum+=0;
        else if(a==1) sum+=500;
        else if(a<=3) sum+=300;
        else if(a<=6) sum+=200;
        else if(a<=10) sum+=50;
        else if(a<=15) sum+=30;
        else if(a<=21) sum+=10;

        if(b==0) sum+=0;
        else if(b==1) sum+=512;
        else if(b<=3) sum+=256;
        else if(b<=7) sum+=128;
        else if(b<=15) sum+=64;
        else if(b<=31) sum+=32;

        cout << sum*10000 << "\n";
    }
    
    return 0;
}