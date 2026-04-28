#include <bits/stdc++.h>
using namespace std;

struct node{
    int width, height, weight, id;

    bool operator<(const node other) const{
        if(width == other.width) return weight < other.weight;
        return width < other.width;
    }
};

int n;
vector<node> v;

void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        v[i] = {a,b,c,i};
    }
}

void solve(){
    sort(v.begin(), v.end());
    vector<int> dp(n); for(int i=0;i<n;i++) dp[i] = v[i].height;
    vector<int> parent(n, -1); 

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){    
            if(v[i].weight > v[j].weight){
                if(dp[i] < dp[j] + v[i].height){
                    parent[i] = j;
                    dp[i] = dp[j] + v[i].height;
                }
            }
        }
    }

    int pos = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> retrack;
    while(pos != -1){
        retrack.push_back(v[pos].id);
        pos = parent[pos];
    }

    cout << retrack.size() << "\n";
    for(int i=retrack.size()-1;i>=0;i--) cout << retrack[i]+1 << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    solve();
    return 0;
}