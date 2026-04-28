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
        int a; cin >> a;
        int num; cin >> num;
        while(num--){
            int b,c; cin >> b >> c;
            a += b*c;
        }
        cout << a <<"\n";
    }
    
    return 0;
}