#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    queue<int> q; stack<int> s;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        q.push(num);
    }
    int cnt = 1;
    for(;;){
        if(!q.empty() && cnt == q.front()){
            q.pop(); cnt++;
        }
        else if(!s.empty() && cnt == s.top()){
            s.pop();
            cnt++;
        }
        else{
            if(!s.empty() && s.top() < q.front()){cout << "Sad"; break;}
            s.push(q.front());
            q.pop();
        } 

        if(cnt==n){cout << "Nice"; break;}
    }
    
    return 0;
}