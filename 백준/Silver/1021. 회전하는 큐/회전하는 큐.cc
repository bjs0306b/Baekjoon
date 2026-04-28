#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,sum=0; cin>>a>>b; deque<int> deq;
    for(int i=1;i<a+1;i++) deq.push_back(i);
    int entry = 1;
    for(int i=0;i<b;i++){
        int num; cin >> num;
        int pos = find(deq.begin(),deq.end(),num) - find(deq.begin(), deq.end(), entry);
        if(pos < 0) pos*=-1;
        int size = deq.size();
        sum += min(size-pos, pos); 
        entry = *(find(deq.begin(),deq.end(),num)+1);
        deq.erase(find(deq.begin(),deq.end(),num)); 
    }
    cout << sum;
    
    
    return 0;
}