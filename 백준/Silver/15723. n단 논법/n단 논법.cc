#include <bits/stdc++.h>
using namespace std;

int A[27];

bool dfs(int n, int m){
    if(n == m) return true;
    if(A[n]) return dfs(A[n], m);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string s; getline(cin, s);
        int a = s[0] - 'a' + 1;
        int b = s[5] - 'a' + 1;
        A[a] = b;
    }
    int m; cin >> m;
    cin.ignore();
    for(int i=0;i<m;i++){
        string s; getline(cin, s);
        int a = s[0] - 'a' + 1;
        int b = s[5] - 'a' + 1;
        if(dfs(a,b)) cout << "T\n";
        else cout << "F\n";
    }
    
    return 0;
}