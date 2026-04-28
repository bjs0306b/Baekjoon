#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >>a>>b;
    deque<int> deq;
    for(int i=0;i<8;i++){
        int num1 = a[i]-'0', num2 = b[i]-'0';
        deq.push_back(num1);
        deq.push_back(num2);
    }
    while(deq.size() > 2){
        int size = deq.size();
        for(int i=0;i<size-1;i++){
            int num = (deq[i]+deq[i+1])%10;
            deq.push_back(num);
        }
        while(size--) deq.pop_front();
    }
    for(auto k : deq) cout << k;
    
    return 0;
}