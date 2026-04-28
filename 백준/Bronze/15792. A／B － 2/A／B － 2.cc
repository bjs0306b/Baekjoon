#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    cout << a/b << ".";
    a = a%b;
    for(int i=0;i<1000 && a;i++){
        cout << 10*a/b;
        a = 10*a%b;
    }
    
    return 0;
}