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
    while(n--){
        int num; cin >> num;
        int suma=0; float sumb=0;
        while(num--){
            int a; float b; cin >> a >> b;
            suma += a;
            sumb += a*b;
        }
        cout << suma << " " << round(sumb/suma*10)/10 << "\n";
    }
    
    return 0;
}