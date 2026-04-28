#include <bits/stdc++.h>
using namespace std;

vector<int> v[61];
bool visited[61];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    queue<int> q; 
    
    q.push(0); visited[0] = true;
    v[0] = {0,0,0,0,0};

    int dx[5] = {60,10,-10,1,-1};
    while(!q.empty()){
        int front = q.front(); q.pop(); 
        for(int i=0;i<5;i++){
            int nx = front + dx[i];
            if(nx >= 0 && nx <= 60 && !visited[nx]){
                visited[nx] = true;
                vector<int> temp = v[front];
                temp[i]++;
                v[nx] = temp;
                q.push(nx);
            }
        }
    }
    v[35] = {0,3,0,5,0};

    for(int i=0;i<n;i++){
        int num; cin >> num; 
        int quotient = num / 60, remainder = num % 60;

        cout << quotient + v[remainder][0] << " ";
        for(int i=1;i<5;i++) cout << v[remainder][i] << " ";
        if(i != n-1) cout << '\n';
    }

    // for(int i=0;i<60;i++){
    //     cout << i << ": ";
    //     for(int j=0;j<5;j++) cout << v[i][j] << " ";
    //     cout << '\n';
    // }

    return 0;
}