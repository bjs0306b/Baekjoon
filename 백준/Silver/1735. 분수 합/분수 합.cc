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
    int a,b,c,d; cin >>a>>b>>c>>d;
    int m = a*d+b*c, n = b*d;
    for(int i = min(m,n); i > 1; i--){
        if(m%i==0 && n%i==0){m/=i; n/=i; break;}
    }
    cout << m << " " << n;
    
    return 0;
}