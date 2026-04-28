#include<bits/stdc++.h>
using namespace std;

bool visited[100001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s,e; cin >> s >> e;
    int cnt = 0;
    queue<int> q;
    if(s == 0){
        cnt++;
        s = 1;
    }
    for(int i=s;i<=100000;i*=2){
        if(i == e) {cout << cnt; return 0;}
        q.push(i);
        visited[i] = true;
    }

    while(!q.empty()){
        cnt++;
        int size = q.size();
        for(int i=0;i<size;i++){
            int temp = q.front();
            q.pop();

            if(temp < 100000){
                for(int j=temp+1;j<=100000;j*=2){
                    if(!visited[j]){
                        if(j == e){cout << cnt; return 0;}
                        q.push(j); visited[j] = true;
                    }
                }
            }
            if(temp > 0){
                if(temp == 1){
                    if(!visited[0]){
                        if(0 == e){cout << cnt; return 0;}
                        q.push(0); visited[0] = true;
                    }
                }
                else{
                    for(int j=temp-1;j<=100000;j*=2){
                        if(!visited[j]){
                            if(j == e){cout << cnt; return 0;}
                            q.push(j); visited[j] = true;
                        }
                    }
                }
            }
        }
    }
    cout << "hello";
    
    
    return 0;
}