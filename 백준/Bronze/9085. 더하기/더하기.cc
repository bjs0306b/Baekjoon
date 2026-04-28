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
        int num; cin >> num;
        int sum = 0; while(num--){int t; cin >> t; sum += t;}
        cout << sum << "\n";
    }
    
    return 0;
}