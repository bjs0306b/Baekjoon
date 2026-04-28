#include<bits/stdc++.h>
using namespace std;

int bridge[101], snake[101];
bool visited[101];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        bridge[a] = b;
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        snake[a] = b;
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    int cnt = 0;
    for(;;){
        cnt++;
        int size = q.size();
        for(int i=0;i<size;i++){
            int temp = q.front();
            q.pop();
            
            if(temp > 93){cout << cnt; return 0;}

            for(int j=1;j<7;j++){
                if(!visited[temp+j]){
                    visited[temp+j] = 1;
                    if(bridge[temp+j] != 0){
                        visited[bridge[temp+j]] = 1;
                        q.push(bridge[temp+j]);
                    }
                    else if(snake[temp+j] != 0){
                        visited[snake[temp+j]] = 1;
                        q.push(snake[temp+j]);
                    }
                    else q.push(temp+j);
                }
            }
        }
    }
    
    
    return 0;
}