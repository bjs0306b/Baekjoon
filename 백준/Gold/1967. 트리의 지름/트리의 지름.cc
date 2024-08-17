// #include<bits/stdc++.h>
// using namespace std;

// struct node {
//     node* parent;
//     node* left;
//     node* right;
//     int n, w, left_best, right_best;

//     node(int num, int weight) : parent(nullptr), left(nullptr), right(nullptr), w(weight), left_best(0), right_best(0), n(num) {}
// };

// node* find(node* root, int num) {
//     if (root == nullptr) return nullptr;
//     if (num == root->n) return root;

//     node* found = find(root->left, num);
//     if (found) return found;

//     return find(root->right, num);
// }

// void insert(node* root, int parent, int child, int weight){
//     node* temp = find(root, parent);
//     if(!temp->left){
//         temp->left = new node(child, weight);
//         temp->left->parent = temp;
//     }
//     else{
//         temp->right = new node(child, weight);
//         temp->right->parent = temp;
//     }
// }

// void leaf(node* root){
//     if(root->left) leaf(root->left);
//     else if(root->right) leaf(root->right);
//     else{ 
//         return;
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n; cin >> n;
//     int ans = 0;
//     node* root = new node(1, 0);
    
//     for(int i=0;i<n;i++){
//         int a,b,c; cin >> a >> b >> c;
//         insert(root, a, b ,c);
//     }
//     // left, right 둘 다 null 인 leaf를 찾아서 거기서 root 까지 올라오면서 각 node의 left, right best를 업데이트함.
//     // 업데이트 할 때마다 left_best + right_best 를 ans와 비교해서 max인 걸로 업데이트.

//     leaf(root);
    
//     return 0;
// }

// 이진트리가 아니어서 폐기.

// #include<bits/stdc++.h>
// using namespace std;

// vector<pair<int,int>> vec[10001];
// int dis[10001];

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n; cin >> n;
//     int ans = 0;
//     set<int> leaf; leaf.insert(1);
//     for(int i=0;i<n-1;i++){
//         int a,b,c; cin >> a >> b >> c;
//         if(leaf.find(a) != leaf.end()){
//             leaf.erase(a);
//         }
//         leaf.insert(b);
//         vec[a].push_back({c,b});
//         vec[b].push_back({c,a});
//     }
//     // for(auto k : leaf) cout << k << " ";

//     for(auto i : leaf){
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         pq.push({0, i});
//         for(int j=1;j<=n;j++) dis[j] = INT32_MAX;
//         dis[i] = 0;

//         while(!pq.empty()){
//             int cur_dis = pq.top().first;
//             int cur_node = pq.top().second;
//             pq.pop();

//             if(dis[cur_node] >= cur_dis){
//                 for(auto next : vec[cur_node]){
//                     int next_dis = next.first;
//                     int next_node = next.second;
//                     if(dis[next_node] > dis[cur_node] + next_dis){
//                         dis[next_node] = dis[cur_node] + next_dis;
//                         pq.push({dis[next_node], next_node});
//                     }
//                 }
//             }   
//         }
//         int mx = *max_element(dis+1, dis+n+1);
//         ans = max(ans, mx);
//     }
//     cout << ans;
    
//     return 0;
// }

// 다중 다익스트라 시간초과 ㅈㅈ...

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[10001];
bool visited[10001];

int ans = 0;

void dfs(int n, int sum){
    ans = max(ans, sum);

    for(auto k : vec[n]){
        if(!visited[k.second]){
            visited[k.second] = true;
            dfs(k.second, sum + k.first);
            visited[k.second] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;

    set<int> leaf; leaf.insert(1);
    for(int i=0;i<n-1;i++){
        int a,b,c; cin >> a >> b >> c;
        if(leaf.find(a) != leaf.end()){
            leaf.erase(a);
        }
        leaf.insert(b);
        vec[a].push_back({c,b});
        vec[b].push_back({c,a});
    }
    // for(auto k : leaf) cout << k << " ";

    for(auto i : leaf){
        fill(visited, visited+10001, 0);
        visited[i] = 1;
        dfs(i, 0);
    }
    cout << ans;
    
    return 0;
}   