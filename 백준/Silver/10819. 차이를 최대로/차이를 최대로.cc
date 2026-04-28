#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int n, arr[9];
int ans = 0;
vector<int> v;
vector<int> ans_v;
bool visited[9];

void dfs(int m){
    if(n == m){
        int sum = 0;
        for(int i=0;i<n-1;i++){
            sum += abs(arr[i]-arr[i+1]);
        }
        ans = max(ans,sum);
    }
    else{
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                arr[m] = v[i];
                dfs(m+1);
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n; for(int i=0;i<n;i++){int num; cin >> num; v.push_back(num);}
    dfs(0);
    cout << ans;
    return 0;
}