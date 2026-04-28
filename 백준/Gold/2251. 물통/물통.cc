#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c;
};

set<int> ans;

bool visited[201][201]; // a, b 방문 체크

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    queue<node> q; q.push({0,0,c});
    visited[0][0] = true;

    while(!q.empty()){
        node front = q.front(); q.pop();

        if(front.a == 0) ans.insert(front.c);

        if(front.a){
            if(front.b != b){
                if(b - front.b >= front.a){
                    if(!visited[0][front.a+front.b]){
                        q.push({0, front.a+front.b, front.c});
                        visited[0][front.a+front.b] = true;
                    }
                }
                else{
                    if(!visited[front.a - (b - front.b)][b]){
                        q.push({front.a - (b - front.b), b ,front.c});
                        visited[front.a - (b - front.b)][b] = true;
                    }
                   
                }
            }

            if(front.c != c){
                if(c - front.c >= front.a){         
                    if(!visited[0][front.b]){
                        q.push({0, front.b, front.a+front.c});
                        visited[0][front.b] = true;
                    }
                }
                else{  
                    if(!visited[front.a - (c - front.c)][front.b]){
                        q.push({front.a - (c - front.c), front.b , c});
                        visited[front.a - (c - front.c)][front.b] = true;
                    }
                }
            }
        }

        if(front.b){
            if(front.a != a){
                if(a - front.a >= front.b){        
                    if(!visited[front.a+front.b][0]){
                        q.push({front.a+front.b, 0, front.c});
                        visited[front.a+front.b][0] = true;
                    }
                }
                else{
                    if(!visited[a][front.b - (a - front.a)]){
                        q.push({a, front.b - (a - front.a),front.c});
                        visited[a][front.b - (a - front.a)] = true;
                    }
                }
            }

            if(front.c != c){
                if(c - front.c >= front.b){
                    if(!visited[front.a][0]){
                        q.push({front.a, 0, front.b+front.c});
                        visited[front.a][0] = true;
                    }      
                }
                else{
                    if(!visited[front.a][front.b]){
                        q.push({front.a, front.b - (c - front.c), c});
                        visited[front.a][front.b] = true;
                    }           
                }
            }
        }

        if(front.c){
            if(front.a != a){
                if(a - front.a >= front.c){
                    if(!visited[front.a+front.c][front.b]){
                        q.push({front.a+front.c, front.b, 0});
                        visited[front.a+front.c][front.b] = true;
                    }
                    
                }
                else{
                    if(!visited[a][front.b]){
                        q.push({a, front.b, front.c - (a - front.a)});
                        visited[a][front.b] = true;
                    }   
                }
            }

            if(front.b != b){
                if(b - front.b >= front.c){
                    if(!visited[front.a][front.b+front.c]){
                        q.push({front.a, front.b+front.c, 0});
                        visited[front.a][front.b+front.c] = true;
                    }
                    
                }
                else{
                    if(!visited[front.a][b]){
                        q.push({front.a, b, front.c - (b - front.b)});
                        visited[front.a][b] = true;
                    }
                    
                }
            }
        }
    }

    for(auto k : ans) cout << k << " ";

    return 0;
}