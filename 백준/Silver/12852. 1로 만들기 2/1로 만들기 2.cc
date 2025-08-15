#include <bits/stdc++.h>
using namespace std;

bool visited[1000000];
string history[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    queue<int> q; q.push(n); visited[n] = true;
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front(); q.pop();
            if(f == 1){
                int temp = n;
                cout << cnt << "\n" << temp << " ";
                for(auto k : history[1]){
                    if(k == '1'){
                        temp /= 3;
                    }
                    else if(k == '2'){
                        temp /= 2;
                    }
                    else{
                        temp--;
                    }
                    cout << temp << " ";
                }
                return 0;
            }

            if(f%3==0 && !visited[f/3]){
                visited[f/3] = true;
                history[f/3] = history[f] + '1';
                q.push(f/3);
            }
            if(f%2==0 && !visited[f/2]){
                visited[f/2] = true;
                history[f/2] = history[f] + '2';
                q.push(f/2);
            }
            if(f>1 && !visited[f-1]){
                visited[f-1] = true;
                history[f-1] = history[f] + '3';
                q.push(f-1);
            }
        }
        cnt++;
    } 
    return 0;
}