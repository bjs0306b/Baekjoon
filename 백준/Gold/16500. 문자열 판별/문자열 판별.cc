#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> as;
bool A[100][100]; // A[a][b] -> a~b가 있음.
set<pair<int,int>> avail_time;
int n;
void input(){
    cin >> s;
    cin >> n;
    as.resize(n); for(int i=0;i<n;i++) cin >> as[i];
}

void check(string a, string b){
    for(int i=0;i<=a.size()-b.size();i++){
        string temp = a.substr(i, b.size());
        if(b == temp)  A[i][i+b.size()-1] = true;
    }       
}

void solve(){
    for(int i=0;i<n;i++) check(s, as[i]);
    int size = s.size();
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                A[j][k] = A[j][k] || (A[j][i] && A[i+1][k]);
            }
        }
    }
    if(A[0][size-1]) cout << 1;
    else cout << 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}