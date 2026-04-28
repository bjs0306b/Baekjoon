#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    while(n--){
        int k; cin >> k;

        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        multiset<int> ms;

        while(k--){
            char c; cin >> c; int num; cin >> num;

            if(c == 'I'){
                max_pq.push(num); min_pq.push(num); ms.insert(num);
            }
            else if(c == 'D'){
                if(num == -1){
                    while(!min_pq.empty() && ms.find(min_pq.top()) == ms.end()) min_pq.pop();
                    if(!min_pq.empty()){
                        ms.erase(ms.find(min_pq.top()));
                        min_pq.pop();
                    }
                }
                else if(num == 1){
                    while(!max_pq.empty() && ms.find(max_pq.top()) == ms.end()) max_pq.pop();
                    if(!max_pq.empty()){
                        ms.erase(ms.find(max_pq.top()));
                        max_pq.pop();
                    }
                }
            }
        }

        if(ms.empty()) cout << "EMPTY\n";
        else{
            while(!max_pq.empty() && ms.find(max_pq.top()) == ms.end()) max_pq.pop();
            while(!min_pq.empty() && ms.find(min_pq.top()) == ms.end()) min_pq.pop();
            cout << max_pq.top() << " " << min_pq.top() << "\n";
        }
    }
    
    return 0;
}