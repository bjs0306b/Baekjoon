#include <bits/stdc++.h>
using namespace std;

int n,m,year;
int A[10][10]; // 위치 당 추가할 양분
int food[10][10]; // 위치 당 양분
vector<int> trees[10][10]; // 위치 당 나무들(int : 나이)

void input(){
    cin >> n >> m >> year;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {cin >> A[i][j]; food[i][j] = 5;}
    for(int i=0;i<m;i++){
        int x,y,z; cin >> x >> y >> z;
        x--, y--;
        trees[x][y].push_back(z);
    }
}

// 각 칸에 어린 나무부터 나이만큼 양분을 먹어 나이가 1 늘어남.
// 양분이 부족하면 죽어 (나이/2) 만큼의 양분이 됨.
void eat_food_or_die(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //cout << "(" << i << "," << j << ")'s tree size :" << trees[i][j].size() << "\n";
            sort(trees[i][j].begin(), trees[i][j].end());
            vector<int> alive;
            int extra_food = 0;
            for(int k=0;k<trees[i][j].size();k++){
                // cout << "food[i][j] : " << food[i][j] << ", trees[i][j][k] : " << trees[i][j][k] << "\n";
                if(food[i][j] >= trees[i][j][k]){
                   
                    food[i][j] -= trees[i][j][k];   
                    alive.push_back(trees[i][j][k] + 1);
                }
                else{
                    extra_food += (trees[i][j][k] / 2);
                }
            }

            // cout << "alive trees : ";
            // for(auto k : alive) cout << k << " ";
            // cout << "\n";
            trees[i][j] = alive;
            food[i][j] += extra_food;
        }
    }
}

int dx[] = {-1,-1,-1,0,1,1,1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};
void make_trees(int x, int y){
    for(int i=0;i<8;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n) trees[nx][ny].push_back(1);
    }
}

void tree_birth(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<trees[i][j].size();k++){
                if(trees[i][j][k] % 5 == 0){
                    make_trees(i,j);
                }
            }
        }
    }
}

void add_food(){
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) food[i][j] += A[i][j];
}

int find_alive_trees(){
    int ret = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ret += trees[i][j].size();
        }
    }
    return ret;
}

void solve(){
    while(year--){
        eat_food_or_die(); 
        tree_birth();
        add_food();
    }

    cout << find_alive_trees();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    solve();

    return 0;
}