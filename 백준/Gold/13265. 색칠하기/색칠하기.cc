#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v[1001];
int A[1001];
bool visited[1001];
vector<pair<int,int>> temp;

void input(){
    cin >> n >> m;
    temp.clear();
    for(int i=1;i<=n;i++){
        v[i].clear();
        visited[i] = false;
    }
	for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        temp.push_back({a,b});
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void allocate_num(int num, int dep){
    visited[num] = true;
    A[num] = dep;
    for(auto k : v[num]){
        if(!visited[k]){
            allocate_num(k, dep+1);
        }
    }
}

bool check_possible(){
    for(auto k : temp){
        if((A[k.first] % 2) == (A[k.second] % 2)) return false;
    }
    return true;
}

void solve() {
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            allocate_num(i, 1);
        }
    }
    if(check_possible()) cout << "possible\n";
    else cout << "impossible\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        input();
        solve();
    }
    
	return 0;
}