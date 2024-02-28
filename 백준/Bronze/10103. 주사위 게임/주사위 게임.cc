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
    int a = 100, b = 100;
    while(n--){
        int m,n; cin >> m >> n;
        if(m>n) b-=m;
        else if(m<n) a-=n;
    }
    cout << a <<"\n" << b;
    
    return 0;
}