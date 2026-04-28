#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int a,sum, arr[11];
char buhos[11];
bool visited[11];
long long mx = -1000000000, mn = 1000000000;
vector<char> v;

void dfs(int n){
    if(n == a-1){
        int sum = arr[0];
        for(int i=0;i<a-1;i++){
            char c = buhos[i];
            if(c == '+') sum += arr[i+1];
            else if(c == '-') sum -= arr[i+1];
            else if(c == '*') sum *= arr[i+1];
            else if(c == '/') sum /= arr[i+1];
        }
        if(mx < sum) mx = sum;
        if(mn > sum) mn = sum;
    }
    else{
        for(int i = 0; i<v.size();i++){
            if(!visited[i]){
                buhos[n] = v[i];
                visited[i] = true;
                dfs(n+1);
                visited[i] = false;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a;
    for(int i=0;i<a;i++) cin >> arr[i];
    int buho[4]; for(int i=0;i<4;i++) cin >> buho[i];
    while(buho[0]--) v.push_back('+');
    while(buho[1]--) v.push_back('-');
    while(buho[2]--) v.push_back('*');
    while(buho[3]--) v.push_back('/');
    
    dfs(0);
    cout << mx << "\n"<< mn;
    return 0;
}