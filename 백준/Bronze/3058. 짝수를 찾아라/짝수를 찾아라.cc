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
        int sum = 0, mn= 100;
        for(int i=0;i<7;i++){
            int num; cin >> num;
            if(num % 2 == 0){sum += num; mn = min(mn, num);}
        }
        cout << sum << " " << mn << "\n";
    }
    
    return 0;
}