#include <bits/stdc++.h>
using namespace std;

struct node{
  map<string, node*> child;
};
void dfs(node* n, int dep){
    for(auto k : n->child){
        for(int i=0;i<dep*2;i++) cout << '-';
        cout << k.first << "\n";
        dfs(k.second, dep+1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    node* root = new node();
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int m; cin >> m;
        node* cur = root;
        for(int j=0;j<m;j++){
            string s; cin >> s;
            if(cur->child.find(s) == cur->child.end()) cur->child[s] = new node();
            cur = cur->child[s];
        }
    }

    dfs(root, 0);
    
    return 0;
}