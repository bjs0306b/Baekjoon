#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin >> n;
    deque<long long> deq;
    for(long long i=0;i<n;i++){
        long long num; cin >> num;
        deq.push_back(num);
    }
    sort(deq.begin(), deq.end());
    cout << deq.front()*deq.back();
    
    return 0;
}