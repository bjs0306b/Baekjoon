#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> pq;
    while(n--){
        int num; cin >> num; pq.push(num);
    }
    while(!pq.empty()){ int temp = pq.top(); pq.pop(); cout << temp << "\n";}
    
    return 0;
}