#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >>n;
    while(n--){
        int a,b,c; cin >>a>>b>>c;
        if(a < b-c) cout << "advertise\n";
        else if(a > b-c) cout << "do not advertise\n";
        else cout << "does not matter\n";
    }
    return 0;
}