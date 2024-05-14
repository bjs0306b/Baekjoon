#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    queue<int> q;
    int num;
    for(;;){
        cin >> num; if(num == -1) break;

        if(num == 0){
            q.pop();
        }
        else if(q.size() < n){
            q.push(num);
        }
    }
    
    while(q.size() > 0){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}