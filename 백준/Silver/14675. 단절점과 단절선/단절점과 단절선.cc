#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> v[100001];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b;
        if(a == 1){
            if(v[b].size() > 1) cout << "yes\n";
            else cout << "no\n";
        }
        if(a == 2) cout << "yes\n";
    }

    return 0;
}