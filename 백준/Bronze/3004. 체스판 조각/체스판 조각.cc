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
    int n; cin >> n;
    if(n%2){
        cout << (n/2+1)*(n/2+2);
    }
    else cout << pow(n/2+1, 2);
    
    return 0;
}