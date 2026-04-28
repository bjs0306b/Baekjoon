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
    int num;
    for(;;){
        bool check = false;
        set<int> s;
        int cnt=0;
        for(;;){
            cin >> num;
            if(num == -1){
                check = true;
                break;
            }
            if(num == 0) break;

            s.insert(num);
        }

        if(check) break;
        
        for(auto k : s){
            if(s.find(2*k) != s.end()) cnt++;
        }
        cout << cnt << "\n";

    }
    
    
    return 0;
}