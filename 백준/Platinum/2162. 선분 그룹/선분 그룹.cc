#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x1, y1, x2, y2;
};

int n;
vector<node> v;
vector<int> parent;
map<int,int> cnt;

void input()
{
    cin >> n;
    v.resize(n); parent.resize(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
    }
}

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int aa = find(a), bb = find(b);
    if(aa > bb) swap(aa,bb);
    parent[aa] = bb;
}

int ccw(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3){
    int ret = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    return 0;
}

bool is_meet(int a, int b){
    pair<int,int> p1 = {v[a].x1, v[a].y1};
    pair<int,int> p2 = {v[a].x2, v[a].y2};
    pair<int,int> p3 = {v[b].x1, v[b].y1};
    pair<int,int> p4 = {v[b].x2, v[b].y2};

    int ccw1 = ccw(p1,p2,p3),
    ccw2 = ccw(p1,p2,p4),
    ccw3 = ccw(p3,p4,p1),
    ccw4 = ccw(p3,p4,p2);

    if(ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0){
        if(p1 > p2) swap(p1,p2);
        if(p3 > p4) swap(p3,p4);
        return p3 <= p2 && p1 <= p4;
    }
    
    if(ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0) return true;
    return false;
}

void solve(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(is_meet(i,j)){
                merge(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        int num = find(i);
        cnt[num]++;
    }

    cout << cnt.size() << "\n";
    int mx = 0;
    for(auto k : cnt){
        mx = max(mx, k.second);
    }
    cout << mx;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}