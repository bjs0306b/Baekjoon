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
    int n; 
    while(cin >> n){    
        int one = 1;
        int cnt = 1;
        for(;;){
            if(one % n == 0){
                break;
            }
            else{
                one = one*10 + 1;    
                one %= n;      
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    
    
    
    
    return 0;
}