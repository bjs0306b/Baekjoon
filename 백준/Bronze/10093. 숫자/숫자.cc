#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long a,b; cin >> a>> b;
    if(a>b) swap(a,b);
    else if(a==b){
        cout << 0; return 0;
    }
    cout << b-a-1 << "\n";
    while(++a != b) cout << a << " ";
    
    
    return 0;
}
