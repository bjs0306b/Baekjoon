#include<bits/stdc++.h>
using namespace std;

bool visited[100001];
int visitedcnt[100001]; // 똑같은 시간에 들어온 수

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;

    if(a >= b){
        cout << a-b << "\n1";
        return 0; 
    }
    queue<int> q;
    q.push(a);
    visited[a] = true;
    visitedcnt[a] = 1;

    int cnt2 = 0;
    while(!q.empty()){
        int size = q.size();
        
        int cnt = 0;
        set<int> s;
        for(int i=0;i<size;i++){
            int front = q.front();
            q.pop();

            if(front < 100000 && !visited[front+1]){
                visitedcnt[front+1] += visitedcnt[front];
                s.insert(front+1);
            }
            if(front > 0 && !visited[front-1]){
                visitedcnt[front-1] += visitedcnt[front];
                s.insert(front-1);
            }
            if(front < 50001 && !visited[2*front]){
                visitedcnt[2*front] += visitedcnt[front];
                s.insert(2*front);
            }
        }
        for(auto k : s){
            visited[k]= true;
            q.push(k);
        }

        cnt2++;
        if(visitedcnt[b] > 0){
            cout << cnt2 << "\n" << visitedcnt[b];    
            return 0;
        }

    }
    
    
    return 0;
}