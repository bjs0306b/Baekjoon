#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,a,b;
    cin >> n >>a>>b; if(n < a || n < b) {cout << -1; return 0;}
    a--;b--;
    int db = 2, match = 1;
    while(a/db != b/db){
        match++; db*=2;
    }
    cout << match;
    
    return 0;
}