#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <deque>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b, cnt = 1; cin >> a >> b;
    if(a==b){cout << 1; return 0;}
    deque<long long> s; s.push_back(a);
    while(1){
        int size = s.size(); 
        bool check = false;
        cnt++;
        while(size--){
            long long temp = s.front(); s.pop_front();
            long long m = temp*2;
            long long n; 
            if(temp <= 1000000000){n = stoll(to_string(temp)+'1'); s.push_back(n);}
            if(m == b ||  n == b){check = true; break;}
            s.push_back(m);
        }
        if(check) break;
        if(*min_element(s.begin(), s.end()) > b){cnt = -1; break;}
    }
    cout << cnt;
    return 0;
}