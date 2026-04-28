#include <bits/stdc++.h>
using namespace std;

vector<int> v[12];
vector<int> arr(12);
vector<int> sum(6);
vector<bool> visited(12);

void dfs(int n){
    if(n == 12){
        char cc[12]; for(int i=0;i<12;i++) cc[i] = arr[i] + 'A' - 1;
        cout << "...." << cc[0] << "....\n"; 
        cout << "." << cc[1] << "." << cc[2] << "." << cc[3] << "." << cc[4] << ".\n";
        cout << ".." << cc[5] << "..." << cc[6] << "..\n";
        cout << "." << cc[7] << "." << cc[8] << "." << cc[9] << "." << cc[10] << ".\n";
        cout << "...." << cc[11] << "....\n";
        exit(0);
    }
    else{
        if(!arr[n]){ // 0 일떄만만
            int mx = 0;
            for(auto k : v[n]){
                mx = max(mx, sum[k]);
            }
            
            for(int i=1;i<=26-mx && i<13;i++){
                if(!visited[i]){
                    visited[i] = true;
                    arr[n] = i;
                    for(auto k : v[n]) sum[k] += i;
                    dfs(n+1);
                    visited[i] = false;
                    arr[n] = 0;
                    for(auto k : v[n]) sum[k] -= i;
                }
            }
        }
        else dfs(n+1);
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    v[0] = {0,1}, v[1] = {2,3}, v[2] = {0,2}, v[3] = {1,2}, v[4] = {2,4}, v[5] = {0,3},
    v[6] = {1,4}, v[7] = {0,5}, v[8] = {3,5}, v[9] = {4,5}, v[10] = {1,5}, v[11] = {3,4};
    
    int cnt = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            char c; cin >> c;
            if(c == 'x') arr[cnt++] = 0;
            else if(c >= 'A' && c <= 'Z'){
                int temp = c - 'A' + 1;
                for(auto k : v[cnt]){
                    sum[k] += temp;
                }
                arr[cnt++] = temp;
                visited[temp] = true;
            }
        }
    }
    
    // for(int i=0;i<6;i++) cout << sum[i] << " ";
    // cout << "\n";
    // for(int i=0;i<12;i++) cout << arr[i] << " ";

    dfs(0);

    return 0;
}