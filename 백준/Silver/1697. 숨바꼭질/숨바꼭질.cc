#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b, cnt = 0; 
    cin >> a >> b;
    
    deque<int> deq;
    set<int> visited;
    
    deq.push_back(a);
    visited.insert(a);
    
    while(!visited.count(b)){
        deque<int> deq2 = deq;
        deq.clear(); // Clearing deque for next level
        
        while(!deq2.empty()){
            int num = deq2.front();
            deq2.pop_front();
            if(num > 0 && !visited.count(num - 1)){
                deq.push_back(num - 1);
                visited.insert(num - 1);
            }
            if(num < 100000 && !visited.count(num + 1)){
                deq.push_back(num + 1);
                visited.insert(num + 1);
            }
            if(num < 50001 && !visited.count(num * 2)){
                deq.push_back(num * 2);
                visited.insert(num * 2);
            }
        }
        cnt++;
    }
    
    cout << cnt;
    
    return 0;
}
