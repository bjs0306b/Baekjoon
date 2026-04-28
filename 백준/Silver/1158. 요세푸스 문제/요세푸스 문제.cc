#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a>>b;
    deque<int> deq,deq2;
    for(int i=1;i<a+1;i++) deq.push_back(i);
    while(!deq.empty()){
        for(int i=0;i<b-1;i++){
            int temp = deq.front();
            deq.pop_front();
            deq.push_back(temp);
        }
        int temp = deq.front();
        deq.pop_front();
        deq2.push_back(temp);
    }
    cout << "<";
    for(int i=0;i<a-1;i++) cout << deq2[i] <<", ";
    cout << deq2[a-1] << ">";
    
    
    return 0;
}