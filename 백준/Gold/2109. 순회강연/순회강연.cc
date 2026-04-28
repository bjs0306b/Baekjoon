#include <bits/stdc++.h>
using namespace std;

bool visited[10001];

struct node{
    int a,b;

    bool operator<(const node &other){
        if(a == other.a) return b > other.b;
        return a > other.a;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<node> v(n);
    for(int i=0;i<n;i++) cin >> v[i].a >> v[i].b;

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=v[i].b;j>0;j--){
            if(!visited[j]){
                visited[j] = true;
                flag = true;
                break;
            }
        }
        if(flag){
            ans += v[i].a;
        }
    }

    cout << ans;

    return 0;
}