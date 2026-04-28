#include <bits/stdc++.h>
using namespace std;

int n;

bool is_prime(int num){
    if(num == 1) return false;
    for(int i=2;i<=sqrt(num);i++) if(num % i == 0) return false;
    return true;
}

void dfs(int dep, int num){
    if(n == dep){
        cout << num << "\n";
        return;
    }
    for(int i=0;i<10;i++){ 
        if(dep == 0 && i == 0) continue;
        if(is_prime(num*10+i)){
            dfs(dep+1, num*10+i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dfs(0, 0);
    
    return 0;
}