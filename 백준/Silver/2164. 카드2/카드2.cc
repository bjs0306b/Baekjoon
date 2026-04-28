#include <iostream>
using namespace std;
#include <deque>
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    deque<int> deq;
    for(int i=1;i<n+1;i++) deq.push_back(i);
    while(deq.size() != 1){
        deq.pop_front();
        int temp = deq.front();
        deq.pop_front();
        deq.push_back(temp);
    }
    cout << deq.front();
    return 0;
}