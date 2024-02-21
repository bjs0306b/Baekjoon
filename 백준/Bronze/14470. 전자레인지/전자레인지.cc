#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c,d,e; cin >>a>>b>>c>>d>>e;
    if(a < 0){
        cout << (-1*a*c) + d + (b*e);
    }
    else{
        cout << (b-a)*e;
    }
    return 0;
}