#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    deque<int> d;
    for(int i=1;i<n+1;i++) d.push_back(i);
    while(1){
        cout << d.front() << " ";
        d.pop_front(); if(d.empty()) break;
        int temp = d.front();
        d.pop_front(); 
        d.push_back(temp);
    }
    
    return 0;
}