#include <bits/stdc++.h>
using namespace std;

int A[50][50], temp2[50][50], k;

struct node{
    int a,b,c;
};

vector<node> v;

void func(int a, int b, int c){
    a--, b--;
    
    for(int i=1;i<=c;i++){
        int temp = A[a+i][b+i];
        for(int j=0;j<2*i;j++){
            A[a+i-j][b+i] = A[a+i-j-1][b+i];
        }
        for(int j=0;j<2*i;j++){
            A[a-i][b+i-j] = A[a-i][b+i-j-1];
        }
        for(int j=0;j<2*i;j++){
            A[a-i+j][b-i] = A[a-i+j+1][b-i];
        }
        for(int j=0;j<2*i-1;j++){
            A[a+i][b-i+j] = A[a+i][b-i+j+1];
        }
        A[a+i][b+i-1] = temp;
    }  
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m >> k;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> temp2[i][j];
    for(int i=0;i<k;i++){
        int a,b,c; cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    vector<int> p; for(int i=0;i<k;i++) p.push_back(i);
    int mn = INT32_MAX;
    do{
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) A[i][j] = temp2[i][j];
        for(auto kk : p){
            func(v[kk].a, v[kk].b, v[kk].c);
        }

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<m;j++) sum += A[i][j];
            mn = min(mn, sum);
        }
    }while(next_permutation(p.begin(), p.end()));

    cout << mn;
    

    return 0;
}