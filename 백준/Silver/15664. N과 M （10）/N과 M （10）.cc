#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int m,n;
vector<int> v;
int arr[9];
bool visited[9];
void dfs(int a, int s){
    if(n==a){
        for(int i=0;i<n;i++) cout << arr[i] << ' ';
        cout << '\n';
    }
    else{
        int temp = 0;
        for(int i=s;i<m;i++){
            if(!visited[i] && v[i] != temp){
                visited[i] = true;
                arr[a] = v[i];
                temp = arr[a];
                dfs(a+1,i+1);
                visited[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;i++){int num; cin >> num; v.push_back(num);}
    sort(v.begin(),v.end());
    dfs(0,0);
    return 0;
}

// int m,n;
// vector<int> v;
// set<vector<int>> ss;
// int arr[9], before[9];
// bool visited[9];
// void dfs(int a, int s){
//     if(n==a){
//         vector<int> temp;
//         for(int i=0;i<n;i++) temp.push_back(arr[i]);
//         ss.insert(temp);
//     }
//     else{
//         for(int i=s;i<m;i++){
//             if(!visited[i]){
//                 visited[i] = true;
//                 arr[a] = v[i];
//                 dfs(a+1,i+1);
//                 visited[i] = false;
//             }
//         }
//     }
// }
// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     cin >> m >> n;
//     for(int i=0;i<m;i++){int num; cin >> num; v.push_back(num);}
//     sort(v.begin(),v.end());
//     dfs(0,0);
//     for(auto k : ss){
//         for(auto l : k) cout << l << ' ';
//         cout << '\n';
//     }
//     return 0;
// }