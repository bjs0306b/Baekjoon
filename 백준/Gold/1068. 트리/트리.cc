#include <bits/stdc++.h>
using namespace std;

bool A[50][50];
int ans;

void dfs(int n){
    bool flag = true;
    for(int i=0;i<50;i++){
        if(A[n][i]){
            flag = false;
            dfs(i);
        }
    }
    if(flag) ans++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int root;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(num != -1) A[num][i] = true;
        else root = i;
    }
    int m; cin >> m;
    if(m == root){
        cout << 0; return 0;
    }
    for(int i=0;i<50;i++) A[i][m] = false;

    dfs(root);
    cout << ans;

    return 0;
}