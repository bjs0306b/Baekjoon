// 각 섬 번호 매기기 -> 섬에서 갈 수 있는 다른 섬에 대해 거리 저장. 갈 수 없으면 INT32_MAX
// MST?


#include <bits/stdc++.h>
using namespace std;

struct node{
    int i1,i2,dis;

    bool operator<(const node other) const{
        if(dis == other.dis) return i1 > other.i1;
        return dis > other.dis;
    }
};

int n,m, island_cnt;
int A[10][10];
bool visited[10][10];
priority_queue<node> pq;
vector<int> parent;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin >> A[i][j];
        if(A[i][j] == 1) A[i][j] = -1;
    }
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void alloc_num_dfs(int x, int y, int num){
    for(int i=0;i<4;i++){
        int nx = dx[i] + x, ny = dy[i] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == -1 && !visited[nx][ny]){
            A[nx][ny] = num;
            visited[nx][ny] = true;
            alloc_num_dfs(nx, ny, num);
        }
    }
}

void alloc_num(){
    int num = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == -1 && !visited[i][j]){
                visited[i][j] = true;
                A[i][j] = num;
                alloc_num_dfs(i,j,num);
                num++;
            }
        }
    }
    island_cnt = num-1;
}

void print(int num){
    if(num == 1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
    }
        

    if(num == 2){
        while(!pq.empty()){
            cout << pq.top().i1 << " " << pq.top().i2 << " " << pq.top().dis << "\n";
            pq.pop();
        }
    }
        
}

void cal_dis(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x, ny = y;
        for(;;){
            nx += dx[i], ny += dy[i];
            if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)) break;
            if(A[nx][ny] == A[x][y]) break;

            if(A[nx][ny] > 0){
                int dis = max(abs(nx - x), abs(ny - y)) - 1;
                if(dis > 1) pq.push({A[nx][ny], A[x][y], dis});
                break;
            }
        }
    }
}

void store_dis_between_islands(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] > 0){
                cal_dis(i,j);
            }
        }
    }
}

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int aa = find(a), bb = find(b);
    if(aa > bb) swap(aa,bb);
    parent[aa] = bb;
}

int mst(){
    int ret = 0;
    parent.resize(island_cnt+1);
    for(int i=1;i<=island_cnt;i++) parent[i] = i;

    int cnt = island_cnt - 1;
    while(cnt){
        if(pq.empty()) return -1;
        node t = pq.top();
        pq.pop();

        int a = t.i1, b = t.i2;
        int p_a = find(a), p_b = find(b);
        if(p_a == p_b) continue;
        merge(p_a, p_b);
        ret += t.dis;
        cnt--;
        
    }
    return ret;
}

void solve(){
    alloc_num();// 각 섬 번호 매기기
    //print(1);
    store_dis_between_islands();
    //print(2);
    cout << mst();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();
}