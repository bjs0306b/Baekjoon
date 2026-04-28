#include <bits/stdc++.h>
using namespace std;

long long n;
long long parent[100001][18];
long long dep[100001];
long long dis_parent[100001][18];
vector<pair<long long,long long>> v[100001];

void input(){
    cin >> n;
    for(long long i=0;i<n-1;i++){
        long long a,b,c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

void dfs(long long cur, long long d, long long pre){
    dep[cur] = d;
    for(auto k : v[cur]){
        if(pre == k.first) continue;
        parent[k.first][0] = cur;
        dis_parent[k.first][0] = k.second;
        dfs(k.first, d+1, cur);
    }
}

void find_parent(){
    dfs(1, 0, -1);
    
    for(long long j=1;j<18;j++){
        for(long long i=1;i<=n;i++){
            if(parent[i][j-1] != 0){
                parent[i][j] = parent[parent[i][j-1]][j-1];
                dis_parent[i][j] = dis_parent[i][j-1] + dis_parent[parent[i][j-1]][j-1];
            }
        }
    }
}

long long find_dis(long long a, long long b){
    if(dep[a] < dep[b]) swap(a,b);

    long long ret = 0;

    for(long long i=17;i>=0;i--){
        if(dep[a] - (1 << i) >= dep[b]){
            ret += dis_parent[a][i];
            a = parent[a][i]; 
        }
    }

    if(a == b) return ret;

    for(long long i=17;i>=0;i--){
        if(parent[a][i] != parent[b][i]){
            ret += dis_parent[a][i];
            ret += dis_parent[b][i];
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    ret += dis_parent[a][0] + dis_parent[b][0];
    return ret;
}

long long find_node(long long a, long long b, long long c){
    long long original_a = a, original_b = b;
    long long left_hop = 0, right_hop = 0;
    c--;

    if(dep[a] > dep[b]){
        for(long long i=17;i>=0;i--){
            if(dep[a] - (1 << i) >= dep[b]){
                a = parent[a][i];
                left_hop += (1 << i); 
            }
        }
        if(a == b){
            long long ret = original_a;
            for(long long i=17;i>=0;i--){
                if(c - (1 << i) >= 0){
                    ret = parent[ret][i];
                    c -= (1 << i);
                }
            }
            return ret;
        }
    }
    else{
        for(long long i=17;i>=0;i--){
            if(dep[b] - (1 << i) >= dep[a]){
                b = parent[b][i];
                right_hop += (1 << i); 
            }
        }
        if(a == b){
            long long ret = original_b;
            c = right_hop - c;
            for(long long i=17;i>=0;i--){
                if(c - (1 << i) >= 0){
                    ret = parent[ret][i];
                    c -= (1 << i);
                }
            }
            return ret;
        }
    }  

    for(long long i=17;i>=0;i--){
        if(parent[a][i] != parent[b][i]){
            left_hop += (1 << i);
            right_hop += (1 << i);
            a = parent[a][i];
            b = parent[b][i];
        }
    }

     

    if(left_hop + 1 > c){
        long long ret = original_a;
        for(long long i=17;i>=0;i--){
            if(c - (1 << i) >= 0){
                ret = parent[ret][i];
                c -= (1 << i);
            }
        }
        return ret;
    }
    else{
        long long ret = original_b;
        c = right_hop + 1 - (c - left_hop - 1);
        for(long long i=17;i>=0;i--){
            if(c - (1 << i) >= 0){
                ret = parent[ret][i];
                c -= (1 << i);
            }
        }
        return ret;
    }
}

void solve(){
    find_parent();

    long long m; cin >> m;
    for(long long i=0;i<m;i++){
        long long a; cin >> a;
        if(a == 1){
            long long b,c; cin >> b >> c;
            cout << find_dis(b, c) << "\n";
        }
        else if(a == 2){
            long long b,c,d; cin >> b >> c >> d;
            cout << find_node(b,c,d) << "\n";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
   // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}