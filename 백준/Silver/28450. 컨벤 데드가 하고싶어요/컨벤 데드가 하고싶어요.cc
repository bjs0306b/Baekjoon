// #include<bits/stdc++.h>
// using namespace std;

// int a,b;
// long long arr[1001][1001], arr2[1001][1001];
// bool visited[1001][1001];
// long long h;

// void dfs(int x, int y, long long sum){

//     arr2[x][y] = sum;
//     visited[x][y] = true;
//     if(x+1 < a && (!visited[x+1][y] || arr2[x+1][y] > arr2[x][y] + arr[x+1][y])) dfs(x+1, y, arr2[x][y] + arr[x+1][y]);
//     if(y+1 < b && (!visited[x][y+1] || arr2[x][y+1] > arr2[x][y] + arr[x][y+1])) dfs(x, y+1, arr2[x][y] + arr[x][y+1]);
// }

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     cin >> a >> b;

//     for(int i=0;i<a;i++){
//         for(int j=0;j<b;j++){
//             cin >> arr[i][j];
//         }
//     }

//     cin >> h;

//     dfs(0,0,arr[0][0]);

//     if(arr2[a-1][b-1] > h) cout << "NO";
//     else cout << "YES\n" << arr2[a-1][b-1];
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int a,b,h, arr[1001][1001];
bool visited[1001][1001];

struct node{
    int x,y;
    long long sum;

    bool operator>(const node other)const{
        return sum > other.sum;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> a >> b;
    for(int i=0;i<a;i++) for(int j=0;j<b;j++)cin >> arr[i][j];
    cin >> h;
    long long best;
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({0,0,arr[0][0]});
    while(!pq.empty()){
        node temp = pq.top();
        pq.pop();
        int x = temp.x;
        int y = temp.y;
        int sum = temp.sum;
        if(x == a-1 && y == b-1){best = sum; break;}
        if(visited[x][y]) continue;
        visited[x][y] = true;

        if(x+1 < a && !visited[x+1][y]) pq.push({x+1, y, sum + arr[x+1][y]});
        if(y+1 < b && !visited[x][y+1]) pq.push({x, y+1, sum + arr[x][y+1]});
    }   
    if(best > h) cout << "NO" ;
    else cout << "YES\n" << best;

    return 0;
}